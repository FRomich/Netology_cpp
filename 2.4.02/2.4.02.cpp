#include <iostream>

class Shape
{
private:
	std::string name;

protected:
	Shape(std::string name) : name(name)
	{
	}

public:
	virtual ~Shape() = default;

	std::string getName() const
	{
		return name;
	}

	virtual void printInfo() const = 0;
};

class Triangle : public Shape
{
private:
	int lengthA, lengthB, lengthC;
	int angleA, angleB, angleC;

protected:
	Triangle(std::string name_,
			int a, int b, int c,
			int A, int B, int C)
		: Shape(name_),
		lengthA(a),lengthB(b),lengthC(c),
		angleA(A), angleB(B), angleC(C)
	{}

public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Triangle("Треугольник", a, b, c, A, B, C){}
	void printInfo() const override
	{
		std::cout << getName() << ":\n"
			<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << "\n"
			<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << "\n";
 	}
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triangle("Прямоугольный треугольник",	a, b, c, A, B, 90){}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B)
	: Triangle("Равнобедренный треугольник", a, b, a, A, B, A){	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a)
	: Triangle("Равносторонний треугольник",a, a, a, 60, 60, 60)	{}
};


class Quad : public Shape
{
private:
	int lengthA, lengthB, lengthC, lengthD;
	int angleA, angleB, angleC, angleD;

protected:
	Quad(std::string name_,
			int a, int b, int c, int d,
			int A, int B, int C, int D)
	: Shape(name_),
		lengthA(a), lengthB(b), lengthC(c), lengthD(d),
		angleA(A), angleB(B), angleC(C), angleD(D)
	{
	}

public:
	Quad(int a, int b, int c, int d, int A, int B, int C, int D)
		: Quad("Четырёхугольник",
		a, b, c, d,	A, B, C, D){}

	void printInfo() const override
	{
		std::cout << getName() << ":\n"
			<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << " d=" << lengthD << "\n"
			<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << "\n";
	}
};

class Parallelogram : public Quad
{
protected:
	Parallelogram(std::string name_, int a, int b, int A, int B)
	: Quad(name_, a, b, a, b, A, B, A, B){}

public:
	Parallelogram (int a, int b, int A, int B)
	: Parallelogram("Параллелограмм", a, b, A, B){}
};

class  Rhombus : public  Parallelogram
{
protected:
	Rhombus(std::string name_, int a, int A, int B) : Parallelogram(name_, a, a, A, B)
	{
	}

public:
	Rhombus(int a, int A, int B) : Rhombus("Ромб", a, A, B)
	{
	}
};

class Square : public Rhombus
{
public:
	Square(int a) : Rhombus("Квадрат", a, 90, 90){}
};

void print_info(Shape* shape)
{
	shape->printInfo();
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Shape* shapes[] =
	{
		new Triangle(10, 20, 30, 50, 60, 70),
		new RightTriangle(10, 20, 30, 50, 60),
		new IsoscelesTriangle(10, 20, 50, 80),
		new EquilateralTriangle(30),
		new Quad(10, 20, 30, 40, 50, 60, 70, 80),
		new Square(20),
		new Parallelogram(20, 30, 30, 40),
		new Rhombus(30, 30, 40)
	};

	for (Shape* shape : shapes)
	{
		print_info(shape);
		std::cout << '\n';
	}

	for (Shape* shape : shapes)
	{
		delete shape;
	}
}


