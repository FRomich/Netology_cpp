#pragma once
#include "Quad.h"

class Parallelogram : public Quad
{
protected:
	Parallelogram(std::string name_, int a, int b, int A, int B);

public:
	Parallelogram(int a, int b, int A, int B);
};


