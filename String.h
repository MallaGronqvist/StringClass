// String.h
// Date: 24.04.2021
// Author: Malla Grönqvist
// Description: Class for enabling operations on C-strings.

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS  // strcpy()
#endif

#pragma warning(disable : 4996) // strcat()
#pragma once
#ifndef STRING_H // String.h
#define STRING_H

#include <iostream>
#include <cstring>
using std::ostream;
using std::istream;


class String
{
	friend inline ostream& operator<<(ostream& os, const String& pString);
	friend inline istream& operator>>(istream& is, const String& pString);
	friend inline const String operator+(const char* lhs, const String & rhs); 
	friend inline bool operator==(String& lhs, const char* rhs);

public:
	String();
	String(const char* pString);
	String(const String& pString);
	~String();
	const String operator+(const String& s) const;
	const String operator+(const char* s) const;
	String& operator=(const String& pString);
	String& operator=(const char* pString);
	const char* toC_str();
	int getLength();

private:
	char* _strPtr;
	int _strLen;
};

inline ostream& operator<<(ostream& os, const String& pString) {

	os << pString._strPtr;
	return os;
}

inline istream& operator>>(istream& is, String& pString) {

	// First read into a buffer and then assign content to pString.
	char* bufferString = new char[100];
	is >> bufferString;
	pString = String{ bufferString };
	delete[] bufferString;
	return is;
}

inline const String operator+(const char* lhs, const String & rhs) {

	// Catenate lhs and rhs, and create+return a new String object.
	return String(strcat(String(lhs)._strPtr, rhs._strPtr));
}

inline bool operator==(String& lhs, const char* rhs) {

	// Convert lhs to C-string. Compare lhs and rhs.
	if (strcmp((lhs.toC_str()), rhs) == 0)
		return true;
	else
		return false;
}


#endif /* STRING_H */

