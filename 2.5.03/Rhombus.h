#pragma once
#include "Parallelogram.h"


class  Rhombus : public  Parallelogram
{
protected:
	Rhombus(std::string name_, int a, int A, int B);

public:
	Rhombus(int a, int A, int B);
};
