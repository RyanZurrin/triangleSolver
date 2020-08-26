#include "Triangle.h"
#include "exceptionHandler.h"
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

int Triangle::counter = 0;

void Triangle::makeTriangleAsPoints()
{
}

/*______________________________________________________________________________
*/
Triangle::Triangle()
{
	initiate_triangle();
	counter++;
	cout << "count: " << getCount() << endl;
	//cout << "in default constructor" << endl;
}



Triangle::Triangle(double a, double b, double c)
{
	initiate_triangle();
	counter++;
	cout << "count: " << getCount() << endl;
	side_a = a;
	side_b = b;
	side_c = c;
	
	if(checkSides()==true){
		update_triangle();
	}
	else{
		ExceptionHandler oops;
		oops.badTriangle(this);
	}

}

Triangle::Triangle(char m, double s1, double a, double s2)
{	//sss='s', sas='a', ssa ='b', aaa='l', asa='i', aas='n'
	initiate_triangle();
	counter++;
	cout << "count: " << getCount() << endl;
	if (m == 's') // side, side, side(sss)
	{
	solve_by_SSS(s1, a, s2);
	}
	else if (m == 'a') // side angle side(sas)
	{
		solve_by_SAS(s1, a, s2);
	}	
	else if (m == 'b') // side, side, angle(ssa)
	{
		solve_by_SSA(s1, a, s2);
	}
	else if (m == 'l') // angleA, angleB, angleC(aaa)
	{
		solve_by_AAA(s1, a, s2);
	}

	else if (m == 'i') // angleA ,side_c, angleB (asa)
	{
		solve_by_ASA(s1, a , s2);
	}
	else if (m == 'n') // angleA angleC side_c (aas)
	{
		solve_by_AAS(s1, a, s2);		
	}
}



Triangle::Triangle(const Triangle& t)
{
	counter++;
	cout << "count: " << getCount() << endl;
//	cout << "in copy Triangle constructor";

	side_a = t.side_a;
	side_b = t.side_b;
	side_c = t.side_c;
	altSide = t.altSide;
	angle_A = t.angle_A;
	angle_B = t.angle_B;
	angle_C = t.angle_C;
	altAngle_A = t.altAngle_A;
	altAngle_B = t.altAngle_B;
	altAngle_C = t.altAngle_C;
	perimeter = t.perimeter;
	altPerimeter = t.altPerimeter;
	maxHeight = t.maxHeight;
	area = t.area;
	maxside = t.maxside;
	sVal = t.sVal;
	rVal = t.rVal;
	iVal = t.iVal;
	area = t.area;
	altArea = t.altArea;
	sideType = t.sideType;	
	sssFlag = t.sssFlag;
	aaaFlag = t.aaaFlag;
	sasFlag = t.sasFlag;
	ssaFlag = t.ssaFlag;
	asaFlag = t.asaFlag;
	aasFlag = t.aasFlag;
	altTriFlag = t.altTriFlag;
	
	
	//return *this;
}


const Triangle Triangle::operator=(const Triangle& right)
{
	Triangle temp;
	//cout << "in the overloaded Triangle =operator";
	if (this != &right) {
		//delete this;
		temp.side_a = right.side_a;
		temp.side_b = right.side_b;
		temp.side_c = right.side_c;
		temp.update_triangle();

		return temp;
	}
	return *this;
}

Triangle Triangle::make2rights()
{
	return Triangle();
}
/*______________________________________________________________________________
*/

void Triangle::update_triangle()
{
	if (angle_C > 0 && missingSideFlag == 1) {
		calculate_perimeter();
		calculate_sVal();
		calculate_area();
		calculate_rVal();
		calculate_iVal();
		calculate_angleA();
		calculate_angleB();
		find_base();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	else if (maxside > 0 && maxHeight > 0) {
		calculate_area();
		calculate_All_angles();
		calculate_rVal();
		calculate_sVal();
		calculate_perimeter();
		calculate_iVal();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	else if (side_a > 0 && side_b > 0 && side_c > 0 &&
		angle_A > 0 && angle_B > 0 && angle_C > 0)
	{
		calculate_perimeter();
		calculate_sVal();
		calculate_area();
		calculate_rVal();
		calculate_iVal();
		find_base();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	else {
		calculate_perimeter();
		calculate_sVal();
		calculate_area();
		calculate_rVal();
		calculate_iVal();
		calculate_angleA();
		calculate_angleB();
		calculate_angleC();
		find_base();
		calculate_AllHeight();	
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	triangleTypeByAngle();
	triangleTypeBySide();
}

void Triangle::initiate_triangle()
{
	_triPtr = this;
	maxside = 0.0;
	maxHeight = 0.0;
	height_a = 0.0;
	height_b = 0.0;
	height_c = 0.0;
	altHeight_a = 0.0;
	altHeight_b = 0.0;
	altHeight_c = 0.0;
	side_a = 0.0;
	side_b = 0.0;
	side_c = 0.0;
	altSide = 0.0;
	angle_A = 0.0;
	angle_B = 0.0;
	angle_C = 0.0;
	altAngle_A = 0.0;
	altAngle_B = 0.0;
	altAngle_C = 0.0;
	area = 0.0;
	altArea = 0.0;
	perimeter = 0.0;
	altPerimeter = 0.0;
	median_a = 0.0; altMedian_a = 0.0;
	median_b = 0.0; altMedian_b = 0.0;
	median_c = 0.0; altMedian_c = 0.0;
	sssFlag = 0.0;
	aaaFlag = 0.0;
	sasFlag = 0.0;
	ssaFlag = 0.0;
	asaFlag = 0.0;
	aasFlag = 0.0;
	missingSideFlag = 0.0;
	altTriFlag = 0.0;
	rVal = 0.0;
	sVal = 0.0;
	iVal = 0.0;
	altRval = 0.0;
	altSval = 0.0;
	altIval = 0.0;
	

}

void Triangle::calculate_angleA()
{
	if (angle_B > 0 && angle_C > 0) {
		angle_A = 180 - (angle_B + angle_C);
	}
	else {
		angle_A = (180 / PI) * asin(side_a / (2 * rVal));
	}
}

void Triangle::calculate_angleB()
{
	if (angle_A > 0 && angle_C > 0) {
		angle_B = 180 - (angle_A + angle_C);
	}
	else {
		angle_B = (180 / PI) * asin(side_b / (2 * rVal));
	}
}

void Triangle::calculate_angleC()
{
	if (angle_B > 0 && angle_A > 0) {
		angle_C = 180 - (angle_A + angle_B);
	}
	else {
		angle_C = (180 / PI) * asin(side_c / (2 * rVal));
	}
		
}

void Triangle::calculate_All_angles()
{
	calculate_angleA();
	calculate_angleB();
	calculate_angleC();
}


void Triangle::calculate_AllHeight()
{
	maxHeight = 2 * area / (maxside);	
	calculate_heightBase_a();
	calculate_heightBase_b();
	calculate_heightBase_c();

}

void Triangle::calculate_heightBase_a()
{
	height_a = (2 * area) / side_a;
}

void Triangle::calculate_heightBase_b()
{
	height_b = (2 * area) / side_b;
}

void Triangle::calculate_medians_abc()
{
	double a = 0.0, b = 0.0, c = 0.0;
	a = side_a * side_a;
	b = side_b * side_b;
	c = side_c * side_c;
	median_a = sqrt(((2 * b) + (2 * c) - a) / 4);
	median_b = sqrt(((2 * a) + (2 * c) - b) / 4);
	median_c = sqrt(((2 * a) + (2 * b) - c) / 4);
}

void Triangle::calculate_heightBase_c()
{
	height_c = (2 * area) / side_c;
}

void Triangle::findMissingSide()
{
	missingSideFlag = 1;
	double a, b, angle=0;
	a = side_a;
	//cout <<"a: " << a << endl;

	
	b = side_b;
	//cout <<"b: " << b << endl;
	angle = angle_C;
	//cout <<"angle: " << angle<< endl;
	if (angle == 90) {
		//cout << "in pytho" << endl;
		side_c = pythagoreanTheorem(a, b);
	}
	else {
		//cout << "in else" << endl;
		side_c = sqrt((a * a) + (b * b) - 2 * a * (b * cos(angle*RADIAN)));	
	}
	update_triangle();

}

bool Triangle::checkAngles()
{
	double temp = angle_A + angle_B + angle_C;
	if (temp > 180)
		return false;
	return true;
}

double Triangle::pythagoreanTheorem(double a, double b)
{
	double c;
	c = sqrt(a * a + b * b);
	return c;
}


void Triangle::find_base()
{
	const int size = 3;
	double a, b, c;	
	a = side_a;
	b = side_b;
	c = side_c;
	vector<double> biggestSide = { a, b,  c };
	auto minpos = min_element(biggestSide.cbegin(), biggestSide.cend());
	auto maxpos = max_element(biggestSide.cbegin(), biggestSide.cend());
	sort(biggestSide.begin(), biggestSide.end());
	maxside = biggestSide[2];


}
void Triangle::calculate_area()
{
	if (maxside > 0 && maxHeight > 0) {
		area = (maxHeight * maxside) / 2;
	}else
	   area = sqrt(sVal * (sVal - side_a) * (sVal - side_b) * (sVal - side_c));

}
void Triangle::calculate_perimeter()
{
	perimeter = side_a + side_b + side_c;
}
void Triangle::calculate_rVal()
{
	rVal = (side_a * side_b * side_c) / (4 * area);
}
void Triangle::calculate_sVal()
{
	sVal = perimeter / 2;
}
void Triangle::calculate_iVal()
{
	iVal = area / sVal;
}
Triangle *Triangle::solve_by_AAA(double& a1, double& a2, double& a3)
{
	angle_A = a1; angle_B = a2; angle_C = a3;

	double temp_a=0.0, temp_b=0.0, temp_c=0.0;

	cout << "You need at least one side to solve a triangle\n";
	do {
		cout << "Enter a side length now for the sides you know\n"
			<< "if you do not know a side just enter a 0\n"
			<< "seperate with spaces input order is sides> a, b, c\n>";
		cin >> temp_a >> temp_b >> temp_c;
		if (!cin) {
			cout << "**ERROR**";
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!cin);
	if (temp_a < 0) {
		side_a = abs(temp_a);
	}
	else
		side_a = temp_a;
	
	if (temp_b < 0) {
		side_b = abs(temp_b);
	}
	else
		side_b = temp_b;
	
	if (temp_c < 0) {
		side_c = abs(temp_c);
	}
	else
		side_c= temp_c;

	if (side_a > 0) {
		side_b = sin(angle_B * RADIAN) * side_a / sin(angle_A * RADIAN);
		side_c = sin(angle_C * RADIAN) * side_a / sin(angle_A * RADIAN);
	}
	else if (side_b > 0) {
		side_a = sin(angle_A * RADIAN) * side_b / sin(angle_B * RADIAN);
		side_c = sin(angle_C * RADIAN) * side_b / sin(angle_B * RADIAN);
	}
	else if (side_c > 0) {
		side_a = sin(angle_A * RADIAN) * side_c / sin(angle_C * RADIAN);
		side_b = sin(angle_B * RADIAN) * side_c / sin(angle_C * RADIAN);
	}
	else
		cout << "You didn't enter a valid side lenght, no further computations made on triangle";

	if (temp_a > 0.0) {
		side_a = temp_a;
	}
	if (temp_b > 0.0) {
		side_b = temp_b;
	}
	if (temp_c > 0.0) {
		side_c = temp_c;
	}

	if (checkTriangle() == true) {
		update_triangle();
	}
	else
		cout << "\nthe data entered does not make a valid Triangle. Please try again.";
	
	return this;
}
Triangle *Triangle::solve_by_AAS(double& a1, double& a2, double& s)
{
	//double tmp1, tmp2, tmp3, tmp4;
	angle_A = a1;
	angle_C = a2;
	side_c = s;
	calculate_angleB();
	side_a = sin(a1 * RADIAN) * s / sin(a2 * RADIAN);
	side_b = sin(angle_B*RADIAN) * s / sin(a2 * RADIAN);
	

	if (checkTriangle() == true) {
		update_triangle();
	}
	return this;
}
Triangle *Triangle::solve_by_ASA(double& a1, double& s, double& a2)
{
	angle_A = a1;
	side_c = s;
	angle_B = a2;

	calculate_angleC();

	side_b = sin(angle_B*RADIAN) * s/sin(angle_C*RADIAN);
	side_a = sin(angle_A*RADIAN) * s/sin(angle_C*RADIAN);

	if (checkTriangle() == true) {
		update_triangle();
	}
	return this;
}
Triangle* Triangle::solve_by_SAS(double &s1, double &a, double &s2)
{
	side_a = s1;
	angle_C = a;
	side_b = s2;
	findMissingSide();
	return this;
}
Triangle* Triangle::solve_by_SSA(double& s1, double& s2, double& _a)
{
	double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;
	
	side_a = s1;
	side_b = s2;
	angle_A = _a;
	t1 = s2 / s1;
	t2 = sin(_a * RADIAN);
	t3 = (t1 * t2);
	angle_B = asin(t3) * DEGREE;
	calculate_angleC();
	t4 = side_a * sin(angle_C*RADIAN);
	side_c = t4 / sin(angle_A*RADIAN);
	//side_c = sqrt((s1 * s1) + (s2 * s2) - 2 * s1 * s2 * cos(angle_C));	
	if (checkTriangle() == true) {
		update_triangle();
	}
	else
		cout << "this is a bad tringle" << endl;
	double check = sin(angle_B * RADIAN);
	if (side_b > side_a && check >=0 && check <=1) // checking if an alternate triangle can be made
	{											   // and if so then calculates the alternate data.
		altTriFlag = true;
		altAngle_B = 180 - angle_B;
		altAngle_C = 180 - (angle_A + altAngle_B);
		altSide = side_a * sin(altAngle_C * RADIAN) / sin(angle_A * RADIAN);
		altArea = ( side_a * side_b ) * sin(altAngle_C*RADIAN) / 2;
		altPerimeter = side_a + side_b + altSide;
		altHeight_a = 2 * altArea / side_a;
		altHeight_b = 2 * altArea / side_b;
		altHeight_c = 2 * altArea / altSide;
	}

	return this;

}
Triangle *Triangle::solve_by_SSS(double& s1, double& s2, double& s3) //law of cosines to solve angle C
{	
	side_a = s1;
	side_b = s2;
	side_c = s3;
	if (checkSides() == true) {
		update_triangle();
	}
	else {
		ExceptionHandler oops;
		oops.badTriangle(this);
	}
	return this;
}


void Triangle::check_SSS(Triangle& t)
{

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };
	// Function for SSS similarity 
	//double simi_sss(double s1[], double s2[]);

	sort(s1, s1 + 3);
	sort(s2, s2 + 3);

	// Check for SSS 
	if (s1[0] / s2[0] == s1[1] / s2[1] &&
		s1[1] / s2[1] == s1[2] / s2[2] &&
		s1[2] / s2[2] == s1[0] / s2[0])
		sssFlag = 1;

	sssFlag = 0;

}
void Triangle::check_SAS(Triangle& t)
{// Function for SAS similarity
	
	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };

	sort(a1, a1 + 3);
	sort(a2, a2 + 3);
	sort(s1, s1 + 3);
	sort(s2, s2 + 3);

	// Check for SAS 

	// angle b / w two smallest 
	// sides is largest. 
	if (s1[0] / s2[0] == s1[1] / s2[1])
	{
		if (a1[2] == a2[2])
			sasFlag = 1;
	}
	if (s1[1] / s2[1] == s1[2] / s2[2])
	{
		if (a1[0] == a2[0])
			sasFlag = 1;
	}
	if (s1[2] / s2[2] == s1[0] / s2[0])
	{
		if (a1[1] == a2[1])
			sasFlag = 1;
	}
	sasFlag = 0;
}

void Triangle::check_AAA(Triangle& t)
{

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };


	sort(a1, a1 + 3);
	sort(a2, a2 + 3);

	// Check for AAA 
	if (a1[0] == a2[0] &&
		a1[1] == a2[1] &&
		a1[2] == a2[2])
		aaaFlag = 1;
	else
		aaaFlag = 0;
}
/*______________________________________________________________________________
*/



bool Triangle::checkSides()
{
	if (
		side_a + side_b > side_c &&
		side_c + side_b > side_a &&
		side_a + side_c > side_b
		)
		return true;
	else
		return false;
}

bool Triangle::checkTriangle()
{
	if(checkSides()==true&&checkAngles()==true)
		return true;
	return false;
}

bool Triangle::checkCongruent(Triangle &T)
{
	check_AAA(T);
	check_SAS(T);
	check_SSS(T);
	if (sssFlag == true ||
		sasFlag == true ||
		sssFlag == true
		)
		return true;

	return false;

}
void Triangle::congruentBy(Triangle &T)
{
		if(checkCongruent(T)==true){
				cout << "Triangles are "
					<< "similar by ";
				if (aaaFlag == 1) cout << "AAA ";
				if (sssFlag == 1) cout << "SSS ";
				if (sasFlag == 1) cout << "SAS.";
		}
		else
		 		cout<< "Triangles are not congruent" << endl;

}

void Triangle::triangleTypeBySide()
{
	if (!checkSides()) {
		//cout << "Not a valid triangle" << endl;
		sideType = "invalid";
	}
	else {
		if (side_a == side_b && side_b == side_c) {
			//cout << "Equilateral" << endl;
			sideType = "Equilateral";
		}
		else if (side_a == side_b || side_b == side_c || side_c == side_a) {
			//cout << "Isosceles" << endl;
			sideType = "Isosceles";
		}
		else {
			//cout << "scalene" << endl;
			sideType = "Scalene";
		}

	}
}

void Triangle::triangleTypeByAngle()
{
	double longest, a, b, c;
	a = angle_A;
	b = angle_B;
	c = angle_C;

	if (!checkAngles()) {
		//cout << "Not a valid triangle" << endl;
		//throw ExceptionHandler.
		angleType = "invalid";
	}
	else {
		longest = c;
		
		if (longest < a) {
			c = longest;
			longest = b;
			a = c;
		}

		if (longest < b) {
			c = longest;
			longest = b;
			b = c;
			
		}
		if (a * a + b * b == longest * longest || a == 90 || b == 90 || c==90) {
			//cout << "This is a right-angled triangle.\n";
			angleType = "Right";
		}
		else if (a * a + b * b > longest * longest) {
			//cout << "This is an acute-angled triangle.\n";
			angleType = "Acute";
		}
		else
			//cout << "This is an obtuse-angled triangle.\n";
			angleType = "Obtuse";
	}
}


void Triangle::showTriangle() const
{
	showAngleType();
	showTriangleSides();
	showTriangleAngles();
	showArea();
	showParimeter();
	showSemiperimeter();
	showLargestSide();
	showAllHeights();
	showAllMedians();
	showCircumradius();
	showInradius();
	if (altTriFlag == true) {
		
		cout << "\nthis Triangle has an alternative" << endl;
		cout << "alt angle B: " << altAngle_B << endl;
		cout << "alt angle C: " << altAngle_C << endl;
		cout << "alt side c: " << altSide << endl;
		cout << "alt area: " << altArea << endl;
		cout << "alt perimeter: " << altPerimeter << endl;
		cout << "alt height_a: " << altHeight_a << endl;
		cout << "alt height_b: " << altHeight_b << endl;
		cout << "alt height_c: " << altHeight_c << endl;
	}
	cout << endl << endl;
}

void Triangle::showTriangleSides() const
{
	showSide_a();
	showSide_b();
	showSide_c();
}

void Triangle::showTriangleAngles() const
{
	showAngle_A();
	showAngle_B();
	showAngle_C();

}
void Triangle::showCongruencyFlags() const
{
	cout << "sssFlag: " << sssFlag << endl;
	cout << "sasFlag: " << sasFlag << endl;
	cout << "aaaFlag: " << aaaFlag << endl;
}

void Triangle::showTriangleAsCartesianPoints() const
{
}

void Triangle::showAngleType() const
{
	cout << "type: " << angleType << "  " << sideType << endl;
}
void Triangle::showTriangleAreaParimeter() const
{
	showArea();
	showParimeter();
	
}
void Triangle::setSides(double _a, double _b, double _c)
{
		side_a = _a;
		side_b = _b;
		side_c = _c;
		if (checkSides() == true) {
			update_triangle();
		}
		else {
			ExceptionHandler t;
			t.badTriangle(this);
		}

}
void Triangle::setAngles(double aA, double aB, double aC)
{	
	// this will essentially build a new triangle from the one you have
		angle_A = aA;
		angle_B = aB;
		angle_C = aC;
		double check = aA + aB + aC;
		if (check != 180) {
			do {
				cout << "the angles need to add up to 180 degrees to be a real triangle\n"
					<< "please reenter the sides and make sure the total is 180 degrees.\n"
					<< "use spaces to seperate each angle esample: 40.5 65 79.5\n>";
				cin >> aA >> aB >> aC;
				cin.clear();
				cin.ignore(100, '\n');
			} while (check != 180 || !cin);
		}
		if (checkAngles() == true) {
			solve_by_AAA(aA, aB, aC);
	}
	//update_triangle();
}
/*______________________________________________________________________________
											   overloaded addition opperators*/
Triangle Triangle::operator+() const
{
	return Triangle();
}

Triangle Triangle::operator++()
{
	return Triangle();
}

Triangle Triangle::operator++(int)
{
	return Triangle();
}

Triangle Triangle::operator+(const Triangle& tri)
{
	double a,b,c;
	a = this->side_a + tri.side_a;
	b = this->side_b + tri.side_b;
	c = this->side_c + tri.side_c; 
	return Triangle(a, b, c);
}

Triangle Triangle::operator+(double n)
{
	side_a = side_a + n;
	side_b = side_b + n;
	side_c = side_c + n;
	if (checkSides() == true) {
		update_triangle();
	}
	return Triangle();
}

Triangle& Triangle::operator+=(const Triangle& rhs)
{
	side_a += rhs.side_a;
	side_b += rhs.side_b;
	side_c += rhs.side_c;
	calculate_All_angles();
	return *this;
}
Triangle operator+(double num, Triangle&)
{
	return Triangle();
}
/*
Triangle operator+(Triangle lhs, const Triangle& rhs)
{
	Triangle temp(
			lhs.side_a+rhs.side_a,
			lhs.side_b+rhs.side_b,
			lhs.side_c+rhs.side_c
			);	
	
	temp.update_triangle();
	return temp;
}

*/

/*______________________________________________________________________________
											overloaded subtraction opperators*/

Triangle Triangle::operator-() const
{
	return Triangle();
}

Triangle Triangle::operator--()
{
	return Triangle();
}

Triangle Triangle::operator--(int)
{
	return Triangle();
}

Triangle Triangle::operator-(const Triangle& tri) const
{
	double a,b,c;
	a = this->side_a - tri.side_a;
	b = this->side_b - tri.side_b;
	c = this->side_c - tri.side_c; 
	return Triangle(a, b, c);
}

Triangle Triangle::operator-(double) const
{
	return Triangle();
}

Triangle& Triangle::operator-=(const Triangle& rhs)
{
	side_a -= rhs.side_a;
	side_b -= rhs.side_b;
	side_c -= rhs.side_c;
	calculate_All_angles();
	return *this;
}

Triangle operator-(double num, Triangle&)
{
	return Triangle();
}
/*
Triangle operator-(Triangle lhs, const Triangle&)
{
	return Triangle();
}
*/
/*______________________________________________________________________________
												overloaded division opperators*/
Triangle Triangle::operator/(double d)
{
	return Triangle(side_a/d, side_b/d, side_c/d);
}

Triangle Triangle::operator/(const Triangle& t)
{
	return Triangle(side_a / t.side_a, side_b / t.side_b, side_c / t.side_c);
}

/*______________________________________________________________________________
										 overloaded multiplication opperators*/

Triangle Triangle::operator*(double t) const
{
	return Triangle(side_a * t, side_b * t, side_c * t);
}

Triangle operator*(double s, Triangle& t)
{
	return Triangle(t.side_a * s, t.side_b * s, t.side_c * s);
}

Triangle operator*(Triangle& v, Triangle& s)
{
	Triangle results(v.side_a * s.side_a, v.side_b * s.side_b, v.side_c * s.side_c);

	return results;

}
ostream& operator<<(ostream& os, const Triangle& t)
{
	t.showTriangle();
	return os;
}

istream& operator>>(istream& is, Triangle& t)
{
	return is;

}

/*______________________________________________________________________________
										 overloaded conversion opperators*/
/*
Triangle::operator float()
{
	float temp = area;
	return temp;
}

Triangle::operator double()
{
	double temp = area;
	return temp;
}

Triangle::operator int()
{
	area = round(area);
	int temp = area;
	return temp;
}

Triangle::operator string()
{
	string temp = to_string(area);
	return temp;
}
*/
