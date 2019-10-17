#pragma once

/* 
User the #pragma once directive above, but could have instead used
#ifndef MYCLASS_H
#define MYCLASS_H
...
#endif
*/

#include <iostream>
using namespace std;

class MyClass
{
	public:
		MyClass();				// Constructor (default)
		MyClass(int a);			// Constructor (1 argument)
		MyClass(int a, int b);	// Constructor (2 arguments)

		~MyClass();				// Destructor

		void myPrint() const;	// Prints something

		MyClass operator+(MyClass& obj);	// Overload operator: +

	protected:

	private:
		int regVar;			// A regular variable
		const int constVar;	// A constant variable (i.e., cannnot change after declaration)
};

template <class T>
T sum(T a, T b)		// Template Function -- works for multiple arg types
{
	return a + b;
};

template <class T>
class Pair			// Template Class -- works for multiple arg types
{
	private:
		T first, second;

	public:
		//NOTE: To provide the implementation of the various template functions in
		//a separate file, at file will also need to be #included'd in the main source file
		//Pair(T a, T b);	// Constructor in separate file
		//~Pair();		// Destructor in separate file
		//T bigger();		// Declaration of a method specified in separate file

		Pair(T a, T b) : first(a), second(b)
		{
		}

		~Pair()
		{
		};

		T bigger()
		{
			return (first > second ? first : second);
		};
};

template <>
class Pair<int>			// Template Specialization -- used for a specific data type
{
private:
	int first, second;

public:
	//NOTE: To provide the implementation of the various template functions in
	//a separate file, at file will also need to be #included'd in the main source file
	//Pair(T a, T b);	// Constructor in separate file
	//~Pair();		// Destructor in separate file
	//T bigger();		// Declaration of a method specified in separate file

	Pair(int a, int b) : first(a), second(b)
	{
		cout << "Constructor: Special treatment for int arguments" << endl;
	}

	~Pair()
	{
	}

	int bigger()
	{
		return (first > second ? first : second);
	}
};

// Structure definition
struct MyStruct {
	int a;
	double b;
	char c[30];
};

// Typedef to create a new type
typedef struct {
	int a;
	double b;
	char c[30];
} MyTestType;