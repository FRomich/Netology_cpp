#include "Rhombus.h"

my_shape::Rhombus::Rhombus(std::string name_, int a, int A, int B) : Parallelogram(name_, a, a, A, B)	{}
my_shape::Rhombus::Rhombus(int a, int A, int B) : Rhombus("Ромб", a, A, B){}
