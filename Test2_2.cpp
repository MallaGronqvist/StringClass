/**********************************************************************/
// File:	Test2_2.cpp
// Description:	
// Test program for testing functionality for own class String that
// handles a number of common string-operations. 
// The result of execution is expected to present console 
// outputs like comments suggest.
	
/**********************************************************************/

#include <iostream>
#include "String.h"
using std::cout;
using std::cin;
using std::endl;

class Application
{
public:
	int run();
};

int Application::run()
{
	String str1("Ciao ");
	String str2(str1);
	
	cout << str1 << str2 << endl;	// Shall print "Ciao Ciao "

	str2 = "bella!";
	cout << str1 << str2 << endl;	// Shall print "Ciao bella!"

	String str3;
	cout << "Enter a name: ";
	cin >> str3;	
	// (... The user enters for instance "Max"...)
	str2 = str1 + str3;
	cout << str2 << endl;		// Shall print "Ciao Max"
	str2 = "Arrivederci " + str3;
	cout << str2 << endl;		// Shall print "Arrivederci Max"
	cout << str1 << "and " << "Arrivederci " 
			<< (str1 == "Arrivederci " ? "is " : "is not ") << "the same word!\n";
								// Shall print "Ciao and Arrivederci is not the same word!"
	return 0;
}

int main()
{
	Application myApp;
	return myApp.run();
}