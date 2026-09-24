#pragma once
#include <string>

#include "Shape.h"

namespace my_shape {

	class SHAPELIBRARY_API  Quad : public my_shape::Shape
	{
	private:
		int lengthA, lengthB, lengthC, lengthD;
		int angleA, angleB, angleC, angleD;

	protected:
		Quad(std::string name_,
			int a, int b, int c, int d,
			int A, int B, int C, int D);

	public:
		Quad(int a, int b, int c, int d, int A, int B, int C, int D);

		void printInfo() const override;
	};
}
	