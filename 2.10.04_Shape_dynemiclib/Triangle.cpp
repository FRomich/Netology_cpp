#include "Triangle.h"

#include <iostream>

my_shape::Triangle::Triangle(std::string name_,
                             int a, int b, int c,
                             int A, int B, int C)
		: Shape(name_),
		lengthA(a), lengthB(b), lengthC(c),
		angleA(A), angleB(B), angleC(C)
	{
	}

my_shape::Triangle::Triangle(int a, int b, int c, int A, int B, int C)
		: Triangle("Треугольник", a, b, c, A, B, C) {
	}

void my_shape::Triangle::printInfo() const
{
	std::cout << getName() << ":\n"
		<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << "\n"
		<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << "\n";
}
