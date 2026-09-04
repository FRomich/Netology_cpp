#include <iostream>

class Shape
{
private:
	int numSides;

protected:
	Shape(int num) : numSides(num)
	{}

public:
	Shape() : numSides{ 0 }
	{}

	int getNumSides()
	{
		return numSides;
	}

	std::string getName()
	{
		return "Фигура";
	} 
};

class Triangle: public Shape
{
private:
	std::string name{};

public:
	Triangle() : Shape(3), name{"Треугольник"} {}

	std::string getName()
	{
		return name;
	}
};

class Quad : public Shape
{
private:
	std::string name{};

public:
	Quad() : Shape(4), name { "Четырёхугольник" } {}

	std::string getName()
	{
		return name;
	}
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


