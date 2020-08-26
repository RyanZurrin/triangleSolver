#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef  TRIANGLE_H
#define  TRIANGLE_H
#include <cmath>
#include <string>
#include <utility>
#include <iostream>

using namespace std;

// use the char name as a mode selector in the constructor followed by the
// three values being entered all seperated by commas of course.
//  example->  Triangle exampleConstruct(ssa, 12.5, 9, 75);   <-sample 

// sss uses the the sides_a than side_b than side_c for input order
const char sss = 's'; // sidea sideb sidec input

// sas uses the side a, angle C, than side b for input order
const char sas = 'a'; // side angle side between 

// ssa uses side a, side b, angle A as input order
const char ssa = 'b'; // side side angle not between

// all angles cant be solved further will ask for one side length
const char aaa = 'l'; // all angles *cant go further need to have a side too

// asa uses angle 
const char asa = 'i'; // angleA side_c angleB side between

// asa uses angle A then angle C then side c, as the unput sides at the moment
const char aas = 'n';  // angle angle side not between


class Triangle
{	
	//friend class ExceptionHandler;
private:
	static int counter;
	//double sVal;
	//double rVal;
	void initiate_triangle();
	void calculate_angleA();
	void calculate_angleB();
	void calculate_angleC();
	void calculate_All_angles();	
	void calculate_AllHeight();
	void calculate_heightBase_a(),
			 calculate_heightBase_b(),
			 calculate_heightBase_c();
	void calculate_medians_abc();
	void findMissingSide();		
	void find_base();
	void calculate_area();
	void calculate_perimeter();
	void calculate_rVal();
	void calculate_sVal();
	void calculate_iVal();
	Triangle *solve_by_AAA(double&, double&, double&); // three sides known
	Triangle *solve_by_AAS(double&, double&, double&); // two angles and a side not between
	Triangle *solve_by_ASA(double&, double&, double&); // two angles and a side bewteen them
	Triangle *solve_by_SAS(double&, double&, double&); // two sides and the included angle.
	Triangle *solve_by_SSA(double&, double&, double&); //  two sides and one angle that is not the included angle
	Triangle *solve_by_SSS(double&, double&, double&); //  all three sides of a triangle, but no angles

public:
	Triangle* _triPtr;
	double maxside;
	double height_a, altHeight_a;
	double height_b, altHeight_b;
	double height_c, altHeight_c;
	double maxHeight;
	double side_a;
	double side_b;
	double side_c, altSide;
	double angle_A, altAngle_A;
	double angle_B, altAngle_B;
	double angle_C, altAngle_C;
	double area, altArea;
	double perimeter, altPerimeter;
	double sVal, altSval; // Semiperimeter 
	double rVal, altRval; // Circumradius
	double iVal, altIval; // inradius
	// these bools are for determining cungruency and type
	double median_a, altMedian_a;
	double median_b, altMedian_b;
	double median_c, altMedian_c;
	bool   sssFlag,
		aaaFlag,
		sasFlag,
		ssaFlag,
		asaFlag,
		aasFlag,
		missingSideFlag,
		altTriFlag;
	// these are char flag variables to add to constructor to define what data you are entering

	
	string sideType;
	string angleType;
	
	
	double pythagoreanTheorem(double, double);
	void update_triangle();
	//ExceptionHandler catcher;
	struct TriangleAsCartesianPoints
	{
		pair<double, double> pt1;
		pair<double, double> pt2;
		pair<double, double> pt3;
	}cTri;

	void makeTriangleAsPoints();

	Triangle();
	
	Triangle(double a, double b, double c); // constructs a triangle with given sides and computs all angles
	Triangle(char, double a, double b, double c); // 
	
	Triangle(const Triangle&); // copy constructor
	Triangle make2rights(); // makes two 90 degree triangles by modifiying itself and returning the other part to new object.
	const Triangle operator=(const Triangle& right); //self assignment

	void check_SSS(Triangle&);// by Arnab Kundu 
	void check_SAS(Triangle&);
	void check_AAA(Triangle&);

	bool checkSides();
	bool checkTriangle();
	bool checkAngles();
	void triangleTypeBySide();
	void triangleTypeByAngle();
	bool checkCongruent(Triangle& T);
	void congruentBy(Triangle&);

	void showTriangle()const;
	void showTriangleSides()const;
	void showTriangleAngles()const;
	void showAngleType()const;
	void showTriangleAreaParimeter()const;
	void showSide_a()const { cout << "side a: " << side_a<< endl; }
	void showSide_b()const { cout << "side b: " << side_b << endl; }
	void showSide_c()const { cout << "side c: " << side_c << endl; }
	void showAngle_A()const { cout << "angle A: " << angle_A<< endl; }
	void showAngle_B()const { cout << "angle B: " << angle_B<< endl; }
	void showAngle_C()const { cout << "angle C: " << angle_C<< endl; }
	void showArea()const { cout << "area: " << area << endl; }
	void showParimeter()const { cout << "parameter: "<< perimeter<< endl; }
	void showMaxHeight()const { cout << "Max Height: " << maxHeight << endl; }
	void showHeight_a()const { cout << "height_a: " << height_a << endl; }
	void showHeight_b()const { cout << "height_b: " << height_b << endl; }
	void showHeight_c()const { cout << "height_c: " << height_c << endl; }
	void showMedian_a()const { cout << "median_a: " << median_a << endl; }
	void showMedian_b()const { cout << "median_b: " << median_b << endl; }
	void showMedian_c()const { cout << "median_c: " << median_c << endl; }
	void showVertex()const;
	void showAllHeights()const {
		cout << "height_a: " << height_a << endl
			 << "height_b: " << height_b << endl
			 << "height_c: " << height_c << endl;
	}
	void showAllMedians()const {
		cout << "median_a: " << median_a << endl
			 << "median_b: " << median_b << endl
			 << "median_c: " << median_c << endl;
	}
	void showLargestSide()const { cout << "base: " << maxside << endl; }
	void showCircumradius()const { cout << "circumradius: " << rVal << endl; }
	void showInradius()const { cout << "inradius: " << iVal << endl; }
	void showSemiperimeter()const { cout << "semiperimeter: " << sVal << endl; }
	void showCongruencyFlags()const;
	void showTriangleAsCartesianPoints()const;
	
	
	double returnSide_a()const { return side_a; }
	double returnSide_b()const { return side_b; }
	double returnSide_c()const { return side_c; }
	double returnAngle_A()const { return angle_A; }
	double returnAngle_B()const { return angle_B; }
	double returnAngle_C()const { return angle_C; }
	double returnArea()const { return area; };
	double returnPerimeter()const { return perimeter; }
	double returnBase()const { return maxside; }
	double returnMaxHeight()const { return maxHeight; }
	double returnHeight_a()const { return height_a; }
	double returnHeight_b()const { return height_a; }
	double returnHeight_c()const { return height_c; }
	double returnMedian_a()const { return median_a; }
	double returnMedian_b()const { return median_b; }
	double returnMedian_c()const { return median_c; }
	double returnCirucmradius()const { return rVal; }
	double returnSemiPerimeter()const { return sVal; }
	bool returnSAS()const { return sas; }
	bool returnSSS() const { return sss; }
	bool returnAAA() const { return aaa; }

	double setSide_a(double _a) { side_a = _a; update_triangle(); }
	double setSide_b(double _b) { side_b = _b; update_triangle(); }
	double setSide_c(double _c) { side_c = _c; update_triangle(); }
	void   setSides(double, double, double);
	void    setAngles(double, double, double);
	int getCount() const { return counter; }
	//double setAngle_A(double _A) { angle_A = _A; update_triangle(); }
	//double setAngle_B(double _B) { angle_B = _B; update_triangle(); }
	//double setAngle_C(double _C) { angle_C = _C; update_triangle(); }
	//double setTriangleArea(double tA) { area = tA; update_triangle(); }


	//overloaded relational operators
	bool operator>(const Triangle& s)const { return area > s.area; }
	bool operator>=(const Triangle& s)const { return area >= s.area; }
	bool operator<(const Triangle& s)const { return area < s.area; }
	bool operator<=(const Triangle& s)const { return area <= s.area; }
	bool operator==(const Triangle& s)const { return area == s.area; }
	bool operator!=(const Triangle& s)const { return !(area == s.area); }
	bool operator>(const double& n)const { return area > n; }
	bool operator>=(const double& n)const { return area >= n; }
	bool operator<(const double& n)const { return n < area; }
	bool operator<=(const double& n)const { return n <= area; }
	bool operator==(const double& n)const { return area == n; }
	bool operator!=(const double& n)const { return !(area == n); }

	//overloaded additon operators	

	Triangle operator+()const;
	Triangle operator++();
	Triangle operator++(int);
	Triangle operator+(const Triangle&);
	Triangle operator+(double);
	Triangle& operator+=(const Triangle&);
	friend Triangle operator+(double num, Triangle&);
	//friend Triangle operator+(Triangle lhs, const Triangle&);

	// overloaded subtraction operators 
	Triangle operator-()const;
	Triangle operator--();
	Triangle operator--(int);
	Triangle operator-(const Triangle&)const;
	Triangle operator-(double)const;
	Triangle& operator-=(const Triangle&);
	friend Triangle operator-(double num, Triangle&);
	//friend Triangle operator-(Triangle lhs, const Triangle&);

	Triangle operator*(double value)const;   // multiply

	friend Triangle operator*(double s, Triangle& v);
	friend Triangle operator*(Triangle& v, Triangle& s);
	Triangle operator/(double);    //division
	Triangle operator/(const Triangle&);	

		
	friend ostream& operator<<(ostream&, const Triangle&);
	friend istream& operator>>(istream&, Triangle&);
	/*
	operator float();
	operator double();
	operator int();
	operator string();
	*/

	~Triangle()
	{
		counter--;
		cout << "count now: " << getCount() << endl;
	}
};

#endif // ! TRIANGLE_H
