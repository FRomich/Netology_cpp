#include "Quad.h"

#include <iostream>

#include "CreatingShapeException.h"


Quad::Quad(std::string name_,
           int a, int b, int c, int d,
           int A, int B, int C, int D)
		: Shape(name_),
		lengthA(a), lengthB(b), lengthC(c), lengthD(d),
		angleA(A), angleB(B), angleC(C), angleD(D)
	{
	if (A + B + C + D != 360)
		throw CreatingShapeException(
			"Причина: сумма углов не равна 360");
	}

Quad::Quad(int a, int b, int c, int d, int A, int B, int C, int D)
		: Quad("Четырёхугольник",
			a, b, c, d, A, B, C, D) {}

void Quad::printInfo() const
{
	std::cout << getName() << ":\n"
		<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << " d=" << lengthD << "\n"
		<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << "\n";
}

