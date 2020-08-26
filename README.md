# triangleSolver
gives all information on a triangle when you provide certain other information. There is no GUI or interface to this yet, just a driver and 10 other header and implementation files.

this small program was part of a larger object calculator i was building. this was primarly for learning purposes so i could better understand how classes worked together. This one part is the triangle solving program that works to solve triangles provided certain information. 

Steps you need to take to make this work on your computer.

1) Download the sourcefiles and put them all in one file, this will be the project file for the triangle solver. Name it whatever you like.
    -Numbers.cpp, -Numbers.h, -Shape.cpp, -Shape.h, -Triangle.cpp, -Triangle.h, -TwoDimensional.cpp, -TwoDimensional.h, -exceptionHandler.cpp, -exceptionHandler.h,
    -DriverTestProgram.cpp.. add these files to a new project in your desired c++ IED.

2) The driverTestProgram.cpp has a few sample triangles being constructed for you so you can see how its done. The Triangle Class has 3 overloaded constructors that allow you to
    put in all three sides if you know the lengths of the sides. Triangle(side_a, side_b, side_c).
    if you dont have all three sides but have other info, the Triangle class has a constructor that allows for four arguments, the first being a string of what kind of 
    triangle you wish to solve. (sss,sas,ssa,aaa,asa,aas) these represent the different information patterns and the order you put into the constructor. For instance if I
    had information on two angles and a single side, instead of 3 sides i would use the asa or aas argument in front and then the other relevent inforomation following, example;
    Triangle(asa, 60, 7.5, 30); and that would build that triangle object and fill in all its info. If the triangle object you try to build is invalid it will throw an error and 
    call into the exceptionHandler class to deal with it. Knowing what I do now about dependecies and such I would of done some things differently and handled errors within the
    class itself but it was still fun learning how to implement such things and I did learn a lot. Maybe one day I will update to handle differently.
  
  3) Once the files are added to a project and they are all there (11 files) you can then build the project and play around in the driver program to build new triangles. You can add, subtract, multiply and divide triangles together to make new triangle objects.
  
   
