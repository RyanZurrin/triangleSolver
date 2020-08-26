#pragma once
#ifndef SHAPE_H
#define SHAPE_H


#include "Numbers.h"
#include <string>
#include "TwoDimensional.h"


class Shape : public Numbers
{
public:
	//Shape* ptr;
	Shape(); // empty shape object created
	//template<class T> T makeNewShape(string obj);
	//Square makeNewSquare();
	TwoDimensional shapes;
	//Triangle makeNewTriangle();

	//ThreeDimensional objects;
	//Shape(string); // specify a shape to construct
	~Shape()
	{
		delete this;
	}
		//  destructor

	
	//ThreeDimensional* Object;
};

#endif // !SHAPE_H

/*____________________________________________________________________________
                                Junk Yard                                   */
 



/*
template<class T>
inline Shape<T>::Shape()
{
	Shape = nullptr;
	Object = nullptr;

}

template<class T>
inline Shape<T>::~Shape()
{
	cout << "in the shape destructor" << endl;
	delete this;
}
*/
