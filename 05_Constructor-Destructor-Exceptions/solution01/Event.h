#ifndef EVENT_H
#define EVENT_H
#include <cstring>
#include <iostream>

class Event {

private:
	char* event; 

public:
	Event();
	Event(const char* event);
	~Event();

	void setEvent(const char* event);
	const char* getEvent()const;

	void cpyEvent(const Event& event);
	void printEvent()const;
};

#endif // EVENT_H