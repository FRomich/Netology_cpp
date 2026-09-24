#pragma once
#include "Quad.h"

namespace my_shape {

	class SHAPELIBRARY_API  Parallelogram : public my_shape::Quad
	{
	protected:
		Parallelogram(std::string name_, int a, int b, int A, int B);

	public:
		Parallelogram(int a, int b, int A, int B);
	};
}


