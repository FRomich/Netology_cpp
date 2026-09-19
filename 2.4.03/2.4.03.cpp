#include <iostream>

enum Validity
{
	Valid,
	Invalid
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

	virtual void printInfo() const = 0;
	virtual Validity check() const = 0;
};


class Triangle : public Shape
{
protected:
	int lengthA, lengthB, lengthC;
	int angleA, angleB, angleC;

	Triangle(std::string name_,
		int a, int b, int c,
		int A, int B, int C)
		: Shape(name_, 3),
		lengthA(a), lengthB(b), lengthC(c),
		angleA(A), angleB(B), angleC(C)
	{
	}

public:
	Triangle(int a, int b, int c, int A, int B, int C)
		: Shape("Треугольник", 3),
		lengthA(a), lengthB(b), lengthC(c),
		angleA(A), angleB(B), angleC(C)
	{
	}

	Validity check() const override
	{
		if (angleA + angleB + angleC == 180)
			return Valid;

		return Invalid;
	}

	void printInfo() const override
	{
		std::cout << getName() << ":\n"
			<< ((check() == Valid) ? "Правильная" : "Неправильная") << "\n"
			<< "Количество сторон: " << getNumSides() << "\n"
			<< "Стороны: a=" << lengthA
			<< " b=" << lengthB
			<< " c=" << lengthC << "\n"
			<< "Углы: A=" << angleA
			<< " B=" << angleB
			<< " C=" << angleC << "\n";
	}
};


class RightTriangle : public Triangle
{
public:
	RightTriangle(int a, int b, int c, int A, int B)
		: Triangle("Прямоугольный треугольник", a, b, c, A, B, 90)
	{
	}

	Validity check() const override
	{
		if (Triangle::check() != Valid)
			return Invalid;

		if (angleC != 90)
			return Invalid;

		return Valid;
	}
};


class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle(int a, int b, int A, int B)
		: Triangle("Равнобедренный треугольник", a, b, a, A, B, A)
	{
	}

	Validity check() const override
	{
		if (Triangle::check() != Valid)
			return Invalid;

		if (lengthA != lengthC)
			return Invalid;

		if (angleA != angleC)
			return Invalid;

		return Valid;
	}
};


class EquilateralTriangle : public Triangle
{
public:
	EquilateralTriangle(int a)
		: Triangle("Равносторонний треугольник", a, a, a, 60, 60, 60)
	{
	}

	Validity check() const override
	{
		if (Triangle::check() != Valid)
			return Invalid;

		if (lengthA != lengthB ||
			lengthB != lengthC)
			return Invalid;

		if (angleA != 60 ||
			angleB != 60 ||
			angleC != 60)
			return Invalid;

		return Valid;
	}
};


class Quad : public Shape
{
protected:
	int lengthA, lengthB, lengthC, lengthD;
	int angleA, angleB, angleC, angleD;

	Quad(std::string name_,
		int a, int b, int c, int d,
		int A, int B, int C, int D)
		: Shape(name_, 4),
		lengthA(a), lengthB(b), lengthC(c), lengthD(d),
		angleA(A), angleB(B), angleC(C), angleD(D)
	{
	}

public:
	Quad(int a, int b, int c, int d,
		int A, int B, int C, int D)
		: Shape("Четырёхугольник", 4),
		lengthA(a), lengthB(b), lengthC(c), lengthD(d),
		angleA(A), angleB(B), angleC(C), angleD(D)
	{
	}

	Validity check() const override
	{
		if (angleA + angleB + angleC + angleD == 360)
			return Valid;

		return Invalid;
	}

	void printInfo() const override
	{
		std::cout << getName() << ":\n"
			<< ((check() == Valid) ? "Правильная" : "Неправильная") << "\n"
			<< "Количество сторон: " << getNumSides() << "\n"
			<< "Стороны: a=" << lengthA
			<< " b=" << lengthB
			<< " c=" << lengthC
			<< " d=" << lengthD << "\n"
			<< "Углы: A=" << angleA
			<< " B=" << angleB
			<< " C=" << angleC
			<< " D=" << angleD << "\n";
	}
};


class Parallelogram : public Quad
{
protected:
	Parallelogram(std::string name_, int a, int b, int A, int B)
		: Quad(name_, a, b, a, b, A, B, A, B)
	{
	}

public:
	Parallelogram(int a, int b, int A, int B)
		: Parallelogram("Параллелограмм", a, b, A, B)
	{
	}

	Validity check() const override
	{
		if (Quad::check() != Valid)
			return Invalid;

		if (lengthA != lengthC ||
			lengthB != lengthD)
			return Invalid;

		if (angleA != angleC ||
			angleB != angleD)
			return Invalid;

		return Valid;
	}
};


class Rhombus : public Parallelogram
{
protected:
	Rhombus(std::string name_, int a, int A, int B)
		: Parallelogram(name_, a, a, A, B)
	{
	}

public:
	Rhombus(int a, int A, int B)
		: Rhombus("Ромб", a, A, B)
	{
	}

	Validity check() const override
	{
		if (Parallelogram::check() != Valid)
			return Invalid;

		if (lengthA != lengthB ||
			lengthB != lengthC ||
			lengthC != lengthD)
			return Invalid;

		return Valid;
	}
};


class Square : public Rhombus
{
public:
	Square(int a)
		: Rhombus("Квадрат", a, 90, 90)
	{
	}

	Validity check() const override
	{
		if (Rhombus::check() != Valid)
			return Invalid;

		if (angleA != 90 ||
			angleB != 90 ||
			angleC != 90 ||
			angleD != 90)
			return Invalid;

		return Valid;
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