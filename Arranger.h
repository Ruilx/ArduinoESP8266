#ifndef ARRANGER_H
#define ARRANGER_H

#include <WString.h>
#include <map>

#define _TASK_SLEEP_ON_IDLE_RUN
#define _TASK_STATUS_REQUEST
#define _TASK_PRIORITY
#define _TASK_STD_FUNCTION
#include <TaskScheduler.h>

class Arranger{
	Scheduler scheduler;
	std::map<String, Task&> taskList;

public:
	Arranger(){}

	void addTask(const String &name, Task &task){
		this->scheduler.addTask(task);
		task.enable();
		this->taskList.insert(std::pair<String, Task&>(name, task));
	}

	void deleteTask(const String &name){
		std::map<String, Task &>::const_iterator i = this->taskList.find(name);
		if(i != this->taskList.end()){
			this->scheduler.deleteTask(i->second);
		}
		this->taskList.erase(name);
	}

	const Task& findTask(const String &name) const{
		std::map<String, Task &>::const_iterator i = this->taskList.find(name);
		if(i != this->taskList.end()){
			return i->second;
		}
		return Task();
	}

	inline bool execute(){
		return this->scheduler.execute();
	}
};

Arranger arranger;

#endif // ARRANGER_H
