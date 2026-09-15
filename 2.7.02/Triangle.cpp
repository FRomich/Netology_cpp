#include "Triangle.h"
#include "Shape.h"

#include <iostream>

#include "CreatingShapeException.h"

Triangle::Triangle(std::string name_,
                   int a, int b, int c,
                   int A, int B, int C)
		: Shape(name_),
		lengthA(a), lengthB(b), lengthC(c),
		angleA(A), angleB(B), angleC(C)
	{
	if (A + B + C != 180)
		throw CreatingShapeException(
			"Причина: сумма углов не равна 180");
	}

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
		: Triangle("Треугольник", a, b, c, A, B, C) {
	}

void Triangle::printInfo() const
{
	std::cout << getName() << ":\n"
		<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << "\n"
		<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << "\n";
}
