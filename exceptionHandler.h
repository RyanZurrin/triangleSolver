#ifndef EXCEPTIONHANDLER_H
#define EXCEPTIONHANDLER_H
#include <iostream>
#include <map>

#include "Numbers.h"
using namespace std;


/*
const double PI		 = 3.1415926535898;
const double DEGREE = 180/PI;
const double RADIAN = PI/180; 
*/

class ExceptionHandler //: public std::runtime_error
{
	//friend class Numbers;
	//friend class Square;
	//friend class Triangle;
	//friend class Vector3D;
	friend class Calculator;
	private:
		//void addErrorToList(int, string);
		

	protected:
		//int exceptionCode;
		//string exceptionSource;
		//string exceptionMessage;
		//map<int, string> error_codes;

		

	public:
		bool checkedFlag;
		ExceptionHandler();
		//ExceptionHandler(int);
		//void checkErrorCode(int)const;
		double zeroDivideFix(double);
		template<typename T> T zeroDivisorCheck(T&);
		template<class T> double zeroDivideFix(T&);
		template<typename T> T* negativeNumCheck(T&);
		template<class Triangle> Triangle* badTriangle(Triangle*);
		template<typename T> T negativeNumFix(T&);
		//bool zeroDivisorCheck(double);
		
		//string getExceptionSource(string);
		//string getExceptionMessage(string);
		//int getExceptionCode(int);

};
#endif

template<typename T>
inline T ExceptionHandler::zeroDivisorCheck(T& num)
{
	if (num != 0)
		return 0;
	else 		
		return 1;
}

template<class T>
inline double  ExceptionHandler::zeroDivideFix(T& num)
{
	double temp;
	if (checkedFlag == false && num == 0) {
		do {
			cout << "You cannot divide by zero, please enter a new number\n>:";
			cin >> temp;
			//num = temp;
			return temp;
			cin.ignore(100, '\n');
			cin.clear();
		} while (!cin || temp == 0);
	}
	return temp;
}

template<typename T>
inline T* ExceptionHandler::negativeNumCheck(T& num)
{
	if (num > 0)
		return 0;
	else {
		num = negativeNumFix(num);
	}
	return 0;	
}

template<class Triangle>
inline Triangle* ExceptionHandler::badTriangle(Triangle* T)
{
	Triangle* temp;
	temp = new Triangle;
	ExceptionHandler negchecker;
	double _a, _b, _c;
	cout << "Your triangle is no good, for the ExceptionHandler" << endl
		<< "Im sending back a good trianlge" << endl;
	cout << "**please enter side a: ";
	cin >> _a;
	if (_a <= 0) {
		//negchecker.negativeNumCheck(_a);
		negchecker.negativeNumFix(_a);
	}
	else
		temp->side_a = _a;

	cout << "**please enter side b: ";
	cin >> _b;
	if (_b <= 0) {
		//negchecker.negativeNumCheck(_b);
		negchecker.negativeNumFix(_b);
	}
	else
		temp->side_b = _b;

	cout << "**please enter side c: ";
	cin >> _c;
	if (_c <= 0) {
		//negchecker.negativeNumCheck(_c);
		negchecker.negativeNumFix(_c);
	}
	else
		temp->side_c = _c;
	
	if (temp->checkTriangle() == true) {
		temp->update_triangle();
		T->side_a = temp->side_a;
		T->side_b = temp->side_b;
		T->side_c = temp->side_c;
		T->update_triangle();
		return temp;
	}
	delete temp;
	temp = nullptr;
	return temp;
	//temp->update_triangle();
	
}
template<typename T>
inline T ExceptionHandler::negativeNumFix(T& num)
{
	//double temp;
	if (checkedFlag == false && num < 0) {
		do {
			cout << "You cannot enter a negitive value\n:";
			cout << "making it an absolute value instead";
			num = abs(num);
			//return num;
			cin.ignore(100, '\n');
			cin.clear();
		} while (!cin || num < 0);
		return num;
	}
	return num;
}


/*

template<class Triangle>
inline Triangle ExceptionHandler::*badTriangle(Triangle& T)
{
	Triangle temp;
	ExceptionHandler negchecker;
	double _a, _b, _c;
	cout << "Your triangle is no good, for the ExceptionHandler" << endl
		 << "Im sending back a good trianlge" << endl;
	cout << "**please enter side a: ";
	cin >> _a;
	if (_a <= 0) {
		//negchecker.negativeNumCheck(_a);
		 negchecker.negativeNumFix(_a);
	}
	else
		T.side_a = _a;

	cout << "**please enter side b: ";
	cin >> _b;
	if (_b <= 0) {
		//negchecker.negativeNumCheck(_b);
		 negchecker.negativeNumFix(_b);
	}
	else
		T.side_b = _b;

	cout << "**please enter side c: ";
	cin >> _c;
	if (_c <= 0) {
		//negchecker.negativeNumCheck(_c);
		negchecker.negativeNumFix(_c);
	}
	else
		T.side_c = _c;
	temp.update_triangle();
	return temp;
}
*/
