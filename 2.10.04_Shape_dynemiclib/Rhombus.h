#pragma once
#include "Parallelogram.h"

namespace my_shape
{
	class SHAPELIBRARY_API  Rhombus : public my_shape::Parallelogram
	{
	protected:
		Rhombus(std::string name_, int a, int A, int B);

	public:
		Rhombus(int a, int A, int B);
	};
}
