// String.cpp
// Date: 24.04.2021
// Author: Malla Grönqvist

#include "String.h"
#include <cstring>


String::String()
	: _strPtr{ nullptr }
{
	// Set _strPtr to NUL if no content is given to constructor.
	_strPtr = new char[1];
	_strPtr[0] = '\0';

	_strLen = 1;
}

String::String(const char* pString) {
	
	// Set length of _strPtr and copy content to it.
	_strPtr = new char[strlen(pString) + 1];
	strcpy(_strPtr, pString);
	_strLen = strlen(pString) + 1;
	
}

String::String(const String& pString) {

	// Set length of _strPtr and copy content to it.
	_strPtr = new char[strlen(pString._strPtr) + 1];
	strcpy(_strPtr, pString._strPtr);
	_strLen = strlen(pString._strPtr) + 1;
}

String::~String() {

//	std::cout << "Destructor used on string length: " << this->getLength() << std::endl;
}

String& String::operator=(const String& pString) {

	if (this == &pString)
		return *this;  // If content is same, no need to copy.
	delete[] _strPtr;
	_strPtr = new char[strlen(pString._strPtr) + 1];
	strcpy(_strPtr, pString._strPtr);
	return *this;
}

String& String::operator=(const char* pString) {

	delete[] _strPtr;
	_strPtr = new char[strlen(pString) + 1];
	strcpy(_strPtr, pString);
	return *this;
}

const String String::operator+(const String& s) const {
	
	// Catenate lhs and rhs, and create+return a new String object.
	return String(strcat((String(this->_strPtr))._strPtr, s._strPtr));
	
}

const String String::operator+(const char* s) const {
	
	return String(strcat((String(this->_strPtr))._strPtr, s));
	
} 

const char* String::toC_str() {

	// Rescast to const char*.
	return (const char*)_strPtr;
}

int String::getLength() {

	// Return lenght of string + nullpointer.
	return strlen(this->_strPtr) + 1;
}