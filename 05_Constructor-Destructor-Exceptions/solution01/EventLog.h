#ifndef EVENT_LOG_H
#define EVENT_LOG_H
#include "Event.h"

class EventLog {

private:
	Event* events;
	size_t currentSize;
	size_t capacity;

public:
	EventLog();
	EventLog(Event* events, size_t currentSize, size_t capacity);
	~EventLog();

	void addEvent(const Event& event);
	void print()const;
	void setSize(size_t size);
	void setCapacity(size_t cap);
	
	Event getEventAt(size_t index)const;
	size_t getSize()const;
	size_t getCapacity()const;
};

#endif // EVENT_LOG_H
