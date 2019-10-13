#include "MyClass.h"
#include <iostream>
using namespace std;

MyClass::MyClass() : regVar(0), constVar(0)
{
	// Constructor - default
	cout << "Constructor (default)" << endl;
	cout << "regVar: [" << MyClass::regVar << "], constVar: [" << MyClass::constVar << "]" << endl;
};

MyClass::MyClass(int a) : regVar(a), constVar(0)
{
	// Constructor (1 argument)
	cout << "Constructor (1 variables)" << endl;
	cout << "regVar: [" << MyClass::regVar << "], constVar: [" << MyClass::constVar << "]" << endl;
};

MyClass::MyClass(int a, int b) : regVar(a), constVar(b)
{
	// Constructor (2 argument)
	cout << "Constructor (2 variables)" << endl;
	cout << "regVar: [" << MyClass::regVar << "], constVar: [" << MyClass::constVar << "]" << endl;
};

MyClass::~MyClass()
{
	// Destructor
	cout << "Destructor" << endl;
};

void MyClass::myPrint() const
{
	cout << "regVar: [" << MyClass::regVar << "], constVar: [" << MyClass::constVar << "]" << endl;
}
MyClass MyClass::operator+(MyClass& obj)
{
	MyClass res;	// Object resulting from this operation
	res.regVar = this->regVar + obj.regVar;
	return res;
};

//template <class T>
//Pair<T>::Pair(T a, T b) : first(a), second(b)
//{
//}
//
//template <class T>
//Pair<T>::~Pair()
//{
//};
//
//template <class T>
//T Pair<T>::bigger()
//{
//	return (first > second ? first : second);
//};