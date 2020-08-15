#ifndef UTILS_H
#define UTILS_H

#include <WString.h>
#include <math.h>
#include <stdio.h>

String numberUnitFormat(int number, uint8_t prec = 2, uint16_t unit = 1024, uint8_t baseUnit = 0, const String glue = String()){
	const static char sizeTable[] = {'\0', 'K', 'M', 'G', 'T', 'P', 'E', 'Z', 'Y', 'B', 'N', 'D'};
	uint8_t count = baseUnit;
	double num = double(number);
	while(num >= unit || -num >= unit){
		count++;
		num = num / unit;
		if(count >= 11){
			break;
		}
	}
	if(floor(num) == num){
		return String(int(floor(num))) + glue + sizeTable[count];
	}else{
		char temp[10] = {0};
		sprintf(temp, "%.*f", prec, num);
		return String(temp) + glue + sizeTable[count];
	}
}

#include <user_interface.h>

inline bool boostCpuFreq(uint8_t freq = SYS_CPU_160MHZ){
	return system_update_cpu_freq(freq);
}

inline bool slumpCpuFreq(uint8_t freq = SYS_CPU_80MHZ){
	return system_update_cpu_freq(freq);
}

uint8_t getCpuFreq(){
	return system_get_cpu_freq();
}

#endif // UTILS_H
