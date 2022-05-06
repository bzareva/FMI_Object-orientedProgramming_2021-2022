/*
	Задача 4.

	Реализирайте клас String предвиден за работа със символни низове, който да поддържа следните оператори:

	+ resize: увеличава размера на символният низ.
	+ add: добавя символ в края на низа.
	+ insertAt: вмъква символ на определена позиция.
	+ removeAt: премехва символ на определена позиция.
	+ print: Извежда дадения низ на конзолата.
	+ at: Връща символа на дадена позиция.
*/


#include <random>
#include <ctime>

#include <iostream>
#include <fstream>
#include "String.h"


int main() {

	String s1("Hello there!\n");
	std::cout << s1;								// Operator <<
	s1 = "\nThis is the english alphabet:\n";		// Operator =
	std::cout << s1;

	String s2;
	for (size_t i = 0; i < 26; ++i) {
		s2 += i + 65;								// Add
	}
	std::cout << s2;

	s1 = "\n\nThe 16-th letter is: ";
	std::cout << s1 << s2[15];						// Operator []


	// Make random table. Removes and inserts space at random in 's3'.
	s1 = "\n\nRandom table:\n";
	std::cout << s1;
	srand(time(0));
	String s3;
	s3 = "0123456789";
	for (size_t i = 0; i < 12; ++i) {
		size_t index = rand() % 11;
		s3.insertAt(' ', index);					// InsertAt
		std::cout << s3 << std::endl;
		s3.removeAt(index);							// RemoveAt 
	}

	// Free capacity.
	std::ifstream file("String.h");
	String s4;
	s4.resize(10);
	std::cout << "\n\nCacpacity: " << s4.getCapacity();
	s4.freeUnused();
	std::cout << "\nCapacity: " << s4.getCapacity() << std::endl;

}
