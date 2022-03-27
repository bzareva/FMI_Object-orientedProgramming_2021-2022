#include "EventLog.h"

EventLog::EventLog() {

	capacity    = 1;
	currentSize = 1;
	events = new Event[capacity];
	events[0].setEvent("koncert");
}

EventLog::EventLog(Event* events, size_t currentSize, size_t capacity)
	: currentSize(currentSize), capacity(capacity) {

	if (currentSize > capacity) {
		this->capacity    = currentSize;
		this->currentSize = capacity;
	}
	
	this->events = new Event[this->capacity];

	for (size_t i = 0; i < currentSize; ++i) {
		this->events[i].cpyEvent(events[i]);
	}
}

EventLog::~EventLog() {

	currentSize = 0;
	capacity    = 0;
	delete[] events;
}

void EventLog::addEvent(const Event& event) {

	if (currentSize == capacity) {
		return;
	}

	events[currentSize].cpyEvent(event);
	++currentSize;
}

void EventLog::print()const {

	for (size_t i = 0; i < currentSize; ++i) {
		events[i].printEvent();
	}
}

void EventLog::setSize(size_t size) {

	if (size > 0 && size < capacity) {
		currentSize = size;
	}
}

void EventLog::setCapacity(size_t cap) {

	if (cap > 0 && cap > capacity) {
		capacity = cap;
	}
}