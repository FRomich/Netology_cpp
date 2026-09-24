#pragma once
#include "Triangle.h"

namespace my_shape
{
	class SHAPELIBRARY_API  IsoscelesTriangle : public my_shape::Triangle
	{
	public:
		IsoscelesTriangle(int a, int b, int A, int B);
	};
}