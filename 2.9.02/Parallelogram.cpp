#include "Parallelogram.h"

Parallelogram::	Parallelogram(std::string name_, int a, int b, int A, int B)
		: Quad(name_, a, b, a, b, A, B, A, B) {}

Parallelogram::Parallelogram(int a, int b, int A, int B)
		: Parallelogram("ֿאנאככוכמדנאלל", a, b, A, B) {}

