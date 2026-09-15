#include "Rhombus.h"

Rhombus::Rhombus(std::string name_, int a, int A, int B) : Parallelogram(name_, a, a, A, B)	{}
Rhombus::Rhombus(int a, int A, int B) : Rhombus("Ромб", a, A, B){}
