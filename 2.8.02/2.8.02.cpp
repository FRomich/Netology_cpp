#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

	int NOD(int numA, int numB) const
	{
		while (numB != 0)
		{
			int temp = numB;
			numB = numA % numB;
			numA = temp;
		}

		return numA;
	}

public:
	Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator)
	{
		int nod = NOD(numerator_, denominator_);

		numerator_ /= nod;
		denominator_ /= nod;
	}

	std::string print() const
	{
		return std::to_string(numerator_) + "/" + std::to_string(denominator_);
	}

	bool operator == (const Fraction& other) const
	{
		return numerator_ * other.denominator_ == denominator_ * other.numerator_;
	}

	bool operator != (const Fraction& other) const
	{
		return !(*this == other);
	}

	bool operator > (const Fraction& other) const
	{
		return numerator_ * other.denominator_ > denominator_ * other.numerator_;
	}

	bool operator < (const Fraction& other) const
	{
		return other > *this;
	}

	bool operator >= (const Fraction& other) const
	{
		return !(*this < other);
	}

	bool operator <= (const Fraction& other) const
	{
		return !(*this > other);
	}

	Fraction operator + (const Fraction& other) const
	{
		return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_,
			denominator_ * other.denominator_);
	}

	Fraction operator - (const Fraction& other) const
	{
		return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_,
			denominator_ * other.denominator_);
	}

	Fraction operator * (const Fraction& other) const
	{
		return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
	}

	Fraction operator / (const Fraction& other) const
	{
		return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
	}

	Fraction operator-() const
	{
		return Fraction(-numerator_, denominator_);
	}

	Fraction& operator ++()
	{
		numerator_ += denominator_;
		return *this;
	}

	Fraction& operator --()
	{
		numerator_ -= denominator_;
		return *this;
	}

	Fraction operator ++(int)
	{
		Fraction old = *this;
		numerator_ += denominator_;
		return old;
	}

	Fraction operator --(int)
	{
		Fraction old = *this;
		numerator_ -= denominator_;
		return old;
	}

};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int numA, denomA, numB, denomB;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numA;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denomA;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numB;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denomB;

	Fraction a{ numA, denomA };
	Fraction b{ numB, denomB };

    std::cout << a.print() << " + " << b.print() << " = " << (a + b).print() << "\n";
	std::cout << a.print() << " - " << b.print() << " = " << (a - b).print() << "\n";
	std::cout << a.print() << " * " << b.print() << " = " << (a * b).print() << "\n";
	std::cout << a.print() << " / " << b.print() << " = " << (a / b).print() << "\n";
	std::cout << "++" << a.print() << " * " << b.print() << " = " << (++a * b).print() << "\n";
	std::cout << "Значение дроби 1: " << a.print() << "\n";
	std::cout << a.print() << "--" << " * " << b.print() << " = " << (a-- * b).print() << "\n";
	std::cout << "Значение дроби 1: " << a.print() << "\n";
}

