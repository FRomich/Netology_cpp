#pragma once
#include "Shape.h"

namespace my_shape
{

	class SHAPELIBRARY_API Triangle : public Shape
	{
	private:
		int lengthA, lengthB, lengthC;
		int angleA, angleB, angleC;

	protected:
		Triangle(std::string name_,
			int a, int b, int c,
			int A, int B, int C);

	public:
		Triangle(int a, int b, int c, int A, int B, int C);
		void printInfo() const override;
	};
}

