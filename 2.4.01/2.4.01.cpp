#include <iostream>

class Shape
{
private:
	std::string name{"Фигура"};
	int numSides{ 0 };

protected:
	Shape(std::string name_, int num_) : name(name_), numSides(num_)
	{}

public:
	Shape()
	{}

	int getNumSides()
	{
		return numSides;
	}

	std::string getName()
	{
		return name;
	} 
};

class Triangle: public Shape
{
public:
	Triangle() : Shape("Треугольник", 3){}
};

class Quad : public Shape
{
public:
	Quad() : Shape("Четырёхугольник", 4){}
};



int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Количество сторон:\n";

	Shape shape;
	std::cout << shape.getName() << ": " << shape.getNumSides() << "\n";
	Triangle triangle;
	std::cout << triangle.getName() << ": " << triangle.getNumSides() << "\n";
	Quad quad;
	std::cout << quad.getName() << ": "  << quad.getNumSides() << "\n";
	
}


