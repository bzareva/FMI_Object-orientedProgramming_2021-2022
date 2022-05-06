#pragma once
#pragma warning (disable : 4996)


class String {
private:
	static const size_t BUFF_SIZE;

	char* str;
	size_t size, capacity;

public:

	String();
	String(const String&);
	String(const char*);
	~String();

	String& operator=(const String&);	
	String& operator+=(char ch);			// Adds the given character at the end of the string. 
	char operator[](size_t) const;			// Returns the character in position 'index'. 

	void resize(size_t);
	bool insertAt(char, size_t);		// Returns false if the character or the index are invalid.
	bool removeAt(size_t);				// Returns false if 'index' is invalid.
	void freeUnused();					// Frees the unused capacity.

	const char* getCString() const;
	size_t getSize() const;
	size_t getCapacity() const;
};


std::ostream& operator<<(std::ostream&, String);
