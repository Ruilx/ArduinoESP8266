#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <stdint.h>
#include <functional>
typedef std::functional<bool()> messageCallback;

typedef struct Message_t{
	uint8_t mode;
	uint32_t delay;
	messageCallback callback;
}Message;

#include <ArduinoQueue.h>

class MessageQueue{
	ArduinoQueue<Message> messageQueue;

public:
	MessageQueue(unsigned int maxItems = -1, unsigned int maxMem = -1){
		this->messageQueue = ArduinoQueue<Message>(maxItems, maxMem);
	}

	inline void push(const Message &message){
		return this->messageQueue.enqueue(message);
	}

	inline const Message pop(){
		return this->messageQueue.dequeue();
	}

	inline const Message head(){
		return this->messageQueue.getHead();
	}

	inline const Message tail(){
		return this->messageQueue.getTail();
	}

	inline bool isEmpty(){
		return this->messageQueue.isEmpty();
	}

	inline bool isFull(){
		return this->messageQueue.isFull();
	}

	inline uint32_t length(){
		return this->messageQueue.itemCount();
	}

	inline uint32_t maxItemSize(){
		return this->messageQueue.maxQueueSize();
	}

	inline uint32_t maxMemSize(){
		return this->messageQueue.maxMemorySize();
	}

	void doMessage(){
		if(!this->messageQueue.isEmpty()){
			Message msg = this->messageQueue.head();
			if(msg.delay > 0){
				delay(msg.delay);
			}
			if(msg.callback != nullptr){
				if(msg.callback()){
					this->messageQueue.dequeue();
					return;
				}
			}
		}
	}
};

MessageQueue messageQueue(64);
MessageQueue messageQueueHighPriority(32);

#endif // MESSAGEQUEUE_H
