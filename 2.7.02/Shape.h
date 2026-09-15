#pragma once
#include <string>

class Shape
{
private:
	std::string name;

protected:
	Shape(std::string name);

public:
	virtual ~Shape() = default;

	std::string getName() const;
	virtual void printInfo() const = 0;
};


