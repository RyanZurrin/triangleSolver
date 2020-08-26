#pragma once
#ifndef NUMBERS_H
#define NUMBERS_H
#include <complex>
#include <cmath>
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <cassert>

//#include "Eigan/Eigen/Core"

using namespace std;
class ccomplex;

const double PI = 3.1415926535898;
const double DEGREE = 180 / PI;
const double RADIAN = PI / 180;

class Numbers 
{
private:
	map<double, string> squareRootsList;
public:
	Numbers();	
	void printOutMap();
	void addNumTranslation(double);
	double checkSquareRoot(double num);
	void checkDecimal(double);
	double squareLoop(int min, int max);
};

#endif