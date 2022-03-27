#include"EventLog.h"

const size_t Size     = 3;
const size_t Capacity = 5;

int main() {

	Event e1("match");
	Event e2("concert");
	Event e3("exam");

	Event events[Size];
	events[0].cpyEvent(e1); 
	events[1].cpyEvent(e2);
	events[2].cpyEvent(e3);

	EventLog log(events, Size, Capacity);

	Event e4("wedding");

	log.addEvent(e4);
	log.print();

	return 0;
}
