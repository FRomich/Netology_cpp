#pragma once
#include "Triangle.h"

namespace my_shape {
	class SHAPELIBRARY_API  RightTriangle : public my_shape::Triangle
	{
	public:
		RightTriangle(int a, int b, int c, int A, int B);
	};
}
