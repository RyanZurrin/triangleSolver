#include "Shape.h"
#include "exceptionHandler.h"
Shape::Shape()
{
	cout << "in_Shape" << endl;
	//ptr = nullptr;
}
/*
Square Shape::makeNewSquare()
{	
		Square token;
		double _s;
		do {
			cout << "enter square side length: ";
			cin >> _s;
			cin.ignore(100, '\n');
			cin.clear();
		} while (!cin || _s < 0);
	
		token.side = _s;
		token.adjust_all();
		return token;
}

Triangle Shape::makeNewTriangle()
{	
		Triangle token;
		double a, b, c;
		do {
			cout << "enter Triangles side lengths with space in between: ";
			cin >> a >> b >> c;
			cin.ignore(100, '\n');
			cin.clear();
		} while (!cin || a < 0 || b < 0 || c < 0);	
		token.side_a = a;
		token.side_b = b;
		token.side_c = c;
		token.update_triangle();
		return token;
}
*/


