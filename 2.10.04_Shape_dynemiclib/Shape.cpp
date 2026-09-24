#include "Shape.h"

#include <iostream>

my_shape::Shape::Shape(std::string name) : name(name){}

std::string my_shape::Shape::getName() const
{
	return name;
}