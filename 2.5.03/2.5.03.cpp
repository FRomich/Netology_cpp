#include <iostream>


#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "Parallelogram.h"
#include "Quad.h"
#include "Rhombus.h"
#include "Shape.h"
#include "Triangle.h"
#include "RightTriangle.h"
#include "Square.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	Shape* shapes[] =
	{
		new Triangle(10, 20, 30, 50, 60, 70),
		new RightTriangle(10, 20, 30, 50, 60),
		new IsoscelesTriangle(10, 20, 50, 80),
		new EquilateralTriangle(30),
		new Quad(10, 20, 30, 40, 50, 60, 70, 80),
		new Square(20),
		new Parallelogram(20, 30, 30, 40),
		new Rhombus(30, 30, 40)
	};

	for (Shape* shape : shapes)
	{
		shape->printInfo();
		std::cout << '\n';
	}

	for (Shape* shape : shapes)
	{
		delete shape;
	}
}

