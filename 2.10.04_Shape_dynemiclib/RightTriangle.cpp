#include "RightTriangle.h"
#include "Triangle.h"

my_shape::RightTriangle::RightTriangle(int a, int b, int c, int A, int B)
	: Triangle("Прямоугольный треугольник", a, b, c, A, B, 90) {
}

