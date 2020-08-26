/*______________________________________________________________________________
author:			Ryan Zurrin
program:		testVect.cpp
due date: 			
assignment:	build and test a Vector class for doing math on vectors	
purpose:    gain a deeper understanding of classes and operator overloading
______________________________________________________________________________*/
//#include "vect.h"
//#include "Vector3D.h"
//#include "Numbers.h"
//#include "TwoDimensional.h"
//#include "ThreeDimensional.h"
//#include "Square.h"
//#include "Shape.h"
#include "Triangle.h"

using namespace std;
//______________________________________________________________________________
//
double squareLoop(int, int);

int main()
{
	/*
	Triangle one(4,5,5);
	one.showTriangle();
	*/
	Numbers objTester;
	objTester.squareLoop(1, 100);
	Triangle testTriangle(2, 2, 3);	
	Triangle test1(4, 5, 5);
	testTriangle.showTriangle();
	test1.showTriangle();
	Triangle test2 = testTriangle + test1;
	test2.showTriangle();
 	

	return 0;

}
////////////////////////////////////////////////////////////////////////////

	

	

