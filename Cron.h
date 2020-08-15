#ifndef CRON_H
#define CRON_H

#include <WString.h>
#include <vector>

#include "Config.h"

/* Cron
 * it describes as a string and has five parts, splited by space:
 *
 * [1] [2] [3] [4] [5]
 *  |   |   |   |   |
 *  |   |   |   |   +--- Week position: 1-6: Monday to Saturday; 0/7: Sunday
 *  |   |   |   +------- Month position: 1-12
 *  |   |   +----------- Day of month: 1-31
 *  |   +--------------- Hour: 0-23
 *  +------------------- Minute: 0-59
 *
 * Every parts can specify exact number or other symbol below:
 * *(asterisk): select all possible numbers
 * ,(comma): select each number splited by commas
 * -(minus): select numbers bewteen minus
 * /(slash): select every number which can devided by number on the right of slash symbol
 *           it start from the minimum calculated phrase before slash.
 */
// Examples:
// "* * * * *" means "Every minute"
// "0 * * * *" means "Every o'clock"
// "0 0 * * *" means "Every begin of the day"
// "*/10 * * * *" means "Every 10 minues"
// "0-29 * * * *" means "First 30 minute in each hour"
// "0-29/10 * * * *" means "0, 10, 20 minute in each hour"
// "1,3,6,8 * * * *" means "1, 3, 6, 8 minute in each hour"

/* Usage:
 *
 *
 */

typedef std::functional<bool()> cronjobCallback;

class Cron{
	typedef struct CronContent_t{
		uint8_t asterisk = 0;
		uint64_t numbers = 0;
		uint8_t slashNumber = 0;
	} CronContent;

	enum {
		ContentMinute = 0,
		ContentHour = 1,
		ContentDay = 2,
		ContentMonth = 3,
		ContentWeek = 4,
	};

	typedef enum {
		ReturnNormal = 0,
		ReturnSyntaxError = 1,
		ReturnCronNotFound,
	} ReturnCode;

	typedef struct Cronjob_t{
		String cronName;
		String cron;
		bool enable;
		ReturnCode error;
		CronContent content[5];
		cronjobCallback callback;
	} Cronjob;

private:
	std::vector<Cronjob>  cronjobs;
	std::vector<Cronjob*> minuteRecord[60];
	std::vector<Cronjob*> hourRecord[24];
	std::vector<Cronjob*> dayRecord[31];
	std::vector<Cronjob*> monthRecord[12];
	std::vector<Cronjob*> weekRecord[7];
	uint8_t maxJobs = 32;
	uint8_t priority = 0;

	CronContent content[5];

	typedef enum {
		PartNone,
		PartNext,
		PartAsterisk,
		PartMinus,
		PartNumber,
		PartSlash,
		PartComma,
		PartError,
	} ContentPart;

	ContentPart parsePart(const char **ptr, const char *ptrEnd, uint8 *number){
		ContentPart part = PartNone;
		*number = 0;
		while((*ptr) < ptrEnd){
			switch(**ptr){
				case ' ':
					if(part == PartNone || part == PartNext){
						part = PartNext;
						break;
					}else{
						return part;
					}
				case '*':
					if(part == PartNone){
						(*ptr)++;
						return PartAsterisk;
					}else{
						return part;
					}
				case '-':
					if(part == PartNone){
						(*ptr)++;
						return PartMinus;
					}else{
						return part;
					}
				case ',':
					if(part == PartNone){
						(*ptr)++;
						return PartComma;
					}else{
						return part;
					}
				case '/':
					if(part == PartSlash){
						(*ptr)++;
						return PartSlash;
					}else{
						return part;
					}
				case '0' ... '9':
					if(part == PartNone || part == PartNumber){
						part = PartNumber;
						*number *= 10;
						*number += **ptr - '0';
						break;
					}else{
						return part;
					}
				default:
					return PartError;
			}
			(*ptr)++;
		}
		return part;
	}

	ReturnCode parseCron(Cronjob &job){
		CronContent *content = job.content;
		uint8_t p = 0;
		const char *cronptr = job.cron.begin();
		const char *cronptrE = job.cron.end();
		uint8_t number = 0;
		uint8_t oldNumber = 0xFF;
		ContentPart part = PartNone;
		bool minusState = false;
		bool commaState = false;
		bool slashState = false;
		while((part = this->parsePart(&cronptr, cronptrE, &number)) != PartNone){
			switch(part){
				case PartNext:
					if(p == 0){
						continue;
					}else if(p < 5){
						p++;
					}else{
						// Partitions greater than 5 and extra expressions will be ignored and report syntax error.
						break;
					}
					break;
				case PartAsterisk:
					if(content[p].asterisk == 0){
						content[p].asterisk = 1;
					}else if(slashState){
						// it cannot apply after slash symbol.
						return ReturnSyntaxError;
					}else{
						// it found more than 2 asterisks in a part will report an syntax error.
						return ReturnSyntaxError;
					}
					break;
				case PartComma:
					if(commaState != false){
						// it found more than 2 comma in conutious and will report syntax error.
						return ReturnSyntaxError;
					}else if(slashState){
						// it cannot apply after slash symbol.
						return ReturnSyntaxError;
					}else{
						commaState = true;
					}
					break;
				case PartMinus:
					if(minusState != false){
						// it found more than 2 minus in conutious and will report syntax error.
						return ReturnSyntaxError;
					}else{
						minusState = true;
					}
					break;
				case PartSlash:
					if(slashState != false){
						// it found more than 2 slash in one part and will report syntax error.
						return ReturnSyntaxError;
					}else{
						slashState = true;
					}
					break;
				case PartNumber:
					if(p == ContentMinute && number >= 60){
						return ReturnSyntaxError;
					}else if(p == ContentHour && number >= 24){
						return ReturnSyntaxError;
					}else if(p == ContentDay && (number > 31 || number == 0)){
						return ReturnSyntaxError;
					}else if(p == ContentMonth && (number > 12 || number == 0)){
						return ReturnSyntaxError;
					}else if(p == ContentWeek && number >= 7){
						return ReturnSyntaxError;
					}
					if(slashState == false){
						uint64_t numloc = (1 << number);
						if(content[p].numbers & numloc){
							// number list already have
						}else{
							if(commaState){
								content[p].numbers &= (1 << number);
								commaState = false;
								oldNumber = number;
							}else if(minusState){
								if(oldNumber == 0xFF || oldNumber > number){
									return ReturnSyntaxError;
								}
								uint8_t delta = number - oldNumber;
								numloc = 0;
								while(delta--){
									numloc |= 1;
									numloc <<= 1;
								}
								while(oldNumber--){
									numloc <<= 1;
								}
								content[p].numbers |= numloc;
								oldNumber = 0xFF;
								minusState = false;
							}else{
								content[p].numbers = numloc;
								oldNumber = number;
							}
						}
					}else{
						content[p].slashNumber = number;
					}
					break;
				default:
					return ReturnSyntaxError;
			}
		}

		// Handle slash number
		for(uint8_t i = 0; i < 5; i++){
			uint8_t minnumber = 0;
			uint64_t getMinNumber = content[i].numbers;
			uint64_t number = 0;
			if(content[i].asterisk){
				if(content[i].slashNumber > 0){
					// if any content has asterisk, ignore any number specified, slashing from 0 on
					while(minnumber <= 60){
						number &= (1 << minnumber);
						minnumber += content[i].slashNumber;
					}
				}else{
					switch(i){
						case ContentMinute:
							number = 0x0FFFFFFFFFFFFFFF;
							break;
						case ContentHour:
							number = 0x0FFFFFF;
							break;
						case ContentDay:
							number = 0x0FFFFFFFE;
							break;
						case ContentMonth:
							number = 0x1FFE;
							break;
						case ContentWeek:
							number = 0x7F;
							break;
					}
				}
				content[i].numbers = number;
			}else if(getMinNumber > 0){
				while(!(getMinNumber & 1)){
					minnumber++;
					getMinNumber >>= 1;
				}
				while(minnumber <= 60){
					// Special:
					// 1-9,11-19/5 means: (24 Hour)
					// digit | 3210 9876543210 9876543210 |
					//       +----------------------------+
					// F Num | 0000 1111111110 1111111110 |
					// Slash | 0010 0001000010 0001000010 | (Slash number start from minNumber)
					// & And +----------------------------+
					// NewNum| 0000 0001000010 0001000010 |
					//       +----------------------------+
					// Result = 1,6,11,16 Hour started
					if(content[i].numbers & (1 << minnumber)){
						number &= (1 << minnumber);
					}
					minnumber += content[i].slashNumber;
				}
				content[i].numbers = number;
			}
		}

		return ReturnNormal;
	}

	bool findCronjob(const String &name, std::vector<Cronjob>::iterator &i){
		i = this->cronjobs.begin();
		bool found = false;
		for(; i < this->cronjobs.end(); i++){
			if((*i).cronName == name){
				found = true;
				break;
			}
		}
		return found;
	}

public:
	Cron(uint8_t maxJobs = 32, priority = 0){
		this->maxJobs = maxJobs;
		this->priority = priority;
	}

	ReturnCode addCron(const String &name, const String &cron, cronjobCallback callback){
		Cronjob job;
		job.cron = cron;
		job.cronName = name;
		ReturnCode returnCode = this->parseCron(job);
		job.error = returnCode;
		this->cronjobs.push_back(job);
		return returnCode;
	}

	ReturnCode removeCron(const String &name){
		std::vector<Cronjob>::iterator i = this->cronjobs.begin();
		bool found = this->findCronjob(name, i);
		if(found && i != this->cronjobs.end()){
			this->cronjobs.erase(i);
			return ReturnNormal;
		}
		return ReturnCronNotFound;
	}

	void setEnable(const String &name, bool enable){
		std::vector<Cronjob>::iterator i = this->cronjobs.begin();
		bool found = this->findCronjob(name, i);
		if(found && i != this->cronjobs.end()){
			(*i).enable = enable;
			return ReturnNormal;
		}
		return ReturnCronNotFound;
	}

	std::vector<Cronjob *>getCronjobs(const DateTime &datetime){
		std::vector<Cronjob *> list;
		for(std::vector<Cronjob>::iterator i = this->cronjobs.begin(); i != this->cronjobs.end(); i++){
			if(!(*i).enable || (*i).error){
				continue;
			}
			do{
				if(!((*i).content[ContentMinute].numbers & datetime.minute)){
					break;
				}
				if(!((*i).content[ContentHour].numbers & datetime.hour)){
					break;
				}
				if(!((*i).content[ContentDay].numbers & datetime.day)){
					break;
				}
				if(!((*i).content[ContentMonth].numbers & datetime.month)){
					break;
				}
				if(!((*i).content[ContentWeek].numbers & datetime.week)){
					break;
				}
				list.push_back(i);
			}while(false);
		}
		return list;
	}


}

#endif // CRON_H
