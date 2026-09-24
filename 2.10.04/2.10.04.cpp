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

	my_shape::Shape* shapes[] =
	{
		new my_shape::Triangle(10, 20, 30, 50, 60, 70),
		new my_shape::RightTriangle(10, 20, 30, 50, 60),
		new my_shape::IsoscelesTriangle(10, 20, 50, 80),
		new my_shape::EquilateralTriangle(30),
		new my_shape::Quad(10, 20, 30, 40, 50, 60, 70, 80),
		new my_shape::Square(20),
		new my_shape::Parallelogram(20, 30, 30, 40),
		new my_shape::Rhombus(30, 30, 40)
	};

	for (my_shape::Shape* shape : shapes)
	{
		shape->printInfo();
		std::cout << '\n';
	}

	for (my_shape::Shape* shape : shapes)
	{
		delete shape;
	}
}
