#include <iostream>
#include <vector>


#include "CreatingShapeException.h"
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

	try
	{
		Shape* shape = new Triangle(10, 20, 30, 60, 60, 70);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new RightTriangle(3, 4, 5, 30, 60);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new IsoscelesTriangle(10, 20, 50, 80);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new EquilateralTriangle(30);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new Quad(10, 20, 30, 40, 50, 60, 70, 80);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new Parallelogram(20, 30, 30, 40);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new Rhombus(30, 30, 40);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}

	try
	{
		Shape* shape = new Square(20);
		shape->printInfo();
		std::cout << "Создан\n";
	}
	catch (const CreatingShapeException& e)
	{
		std::cout << "Ошибка создания фигуры. Причина: "
			<< e.what() << '\n';
	}
}

