#include "Event.h"

Event::Event() {

	const size_t max = 7;
	event = new char[max + 1];
	strcpy_s(event, max + 1, "koncert");	
}

Event::Event(const char* event) {

	size_t size = strlen(event);
	this->event = new char[size + 1];
	strcpy_s(this->event, size + 1, event);
}

Event::~Event() {

	//if (this->event != nullptr) {
		delete[] this->event;
	//}
}

void Event::setEvent(const char* event) {

	size_t size = strlen(event);
	this->event = new char[size + 1];
	strcpy_s(this->event, size + 1, event);
}

const char* Event::getEvent()const {

	return this->event;
}

void Event::cpyEvent(const Event& event) {

	setEvent(event.getEvent());
}

void Event::printEvent()const {

	std::cout << event << std::endl;
}