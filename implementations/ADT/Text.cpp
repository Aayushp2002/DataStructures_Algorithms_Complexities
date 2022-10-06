
#include "Text.h"

Text::Text(const char* charSeq)
{
	
	bufferSize = strlen(charSeq) + 1;
	buffer = new char[bufferSize];
	strcpy(buffer, charSeq);
}

Text::Text(const Text& other)
{
	bufferSize = other.bufferSize;
	buffer = new char[bufferSize];
	strcpy(buffer, other.buffer);

}

void Text::operator = (const Text& other)
{
	if (other.bufferSize > bufferSize) {
		delete[] buffer;
		buffer = new char[other.bufferSize];
	}
	strcpy(buffer, other.buffer);
}

Text::~Text()
{
	delete[] buffer;
}

int Text::getLength() const
{
	return bufferSize - 1;
}

char Text::operator [] (int n) const
{
	if (n > getLength()) {
		return '/0';
	}
	else {
		return buffer[n];
	}
}

void Text::clear()
{
	// buffer.clear();
	// buffer.erase();
	delete[] buffer; // delete and rellocate it so it will be empty
	buffer = new char [bufferSize];
}

void Text::showStructure() const
{
	for (int i = 0; i < getLength(); i++) {
		cout << this[i];
	}
}

Text Text::toUpper() const
{
	Text temp(buffer);
	for (int i = 0; i < temp.getLength(); i++) {
		toupper(temp.buffer[i]);

	}
	return temp;
}

Text Text::toLower() const
{
	Text temp(buffer);
	for (int i = 0; i < temp.getLength(); i++) {
		tolower(temp.buffer[i]);

	}
	return temp;

}

bool Text::operator == (const Text& other) const
{
	return buffer == other.buffer;
}

bool Text::operator <  (const Text& other) const
{
	return buffer < other.buffer;
}

bool Text::operator >  (const Text& other) const
{
	return buffer > other.buffer;
}
