#include "Shape.h"

#include <iostream>

Shape::Shape(std::string name) : name(name){}

std::string Shape::getName() const
{
	return name;
}