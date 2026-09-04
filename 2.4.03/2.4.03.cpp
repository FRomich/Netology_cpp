#include <iostream>

enum Regularity
{
	Regular,
	Irregular
};

class Shape
{
private:
	std::string name;
	int numSides;

protected:
	Shape(std::string name, int numSides)
		: name(name), numSides(numSides)
	{
	}

public:
	virtual ~Shape() = default;

	std::string getName() const
	{
		return name;
	}

	int getNumSides() const
	{
		return numSides;
	}

	void setName(std::string name)
	{
		this->name = name;
	}

	virtual void printInfo() const = 0;
	virtual Regularity check() const = 0;
};

class Triangle : public Shape
{
protected:
	int lengthA, lengthB, lengthC;
	int angleA, angleB, angleC;

public:
	Triangle(int a, int b, int c, int A, int B, int C) : Shape("Треугольник", 3),
		lengthA(a), lengthB(b), lengthC(c),
		angleA(A), angleB(B), angleC(C)
	{
	}

	Regularity check() const override
	{
		if (angleA + angleB + angleC == 180)
			return Regular;

		return Irregular;
	}

	void printInfo() const override
	{
		std::cout << getName() << ":\n"
			<< ((check() == Regular)? "Правильная" : "Неправильная") << "\n"
 			<< "Количество сторон: " << getNumSides() << "\n"
			<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << "\n"
			<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << "\n";
	}
};

class RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
	{
		setName("Прямоугольный треугольник");
	}
};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
	{
		setName("Равнобедренный треугольник");
	}
};

class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
	{
		setName("Равносторонний треугольник");
	}
};


class Quad : public Shape
{
private:
	int lengthA, lengthB, lengthC, lengthD;
	int angleA, angleB, angleC, angleD;

public:
	Quad(int a, int b, int c, int d, int A, int B, int C, int D) : Shape("Четырёхугольник", 4),
		lengthA(a), lengthB(b), lengthC(c), lengthD(d),
		angleA(A), angleB(B), angleC(C), angleD(D)
	{
	}

	Regularity check() const override
	{
		if (angleA + angleB + angleC + angleD == 360)
			return Regular;

		return Irregular;
	}

	void printInfo() const override
	{
		std::cout << getName() << ":\n"
			<< ((check() == Regular) ? "Правильная" : "Неправильная") << "\n"
			<< "Количество сторон: " << getNumSides() << "\n"
			<< "Стороны: a=" << lengthA << " b=" << lengthB << " c=" << lengthC << " d=" << lengthD << "\n"
			<< "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << "\n";
	}
};

class Parallelogram : public Quad
{
public:
	Parallelogram(int a, int b, int A, int B) : Quad(a, b, a, b, A, B, A, B)
	{
		setName("Параллелограмм");
	}
};

class  Rhombus : public  Parallelogram
{
public:
	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
	{
		setName("Ромб");
	}
};

class Square : public Rhombus
{
public:
	Square(int a) : Rhombus(a, 90, 90)
	{
		setName("Квадрат");
	}
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
		new IsoscelesTriangle(10, 20, 50, 60),
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


