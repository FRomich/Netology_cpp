
#include <iostream>

class Calculator
{
private:
    double num1 =0, num2 = 0;

public:

    bool setNum1(double num1)
    {
        if (num1 == 0.0) return false;
    	this->num1 = num1;
        return true;
    }

    bool setNum2(double num2)
    {
        if (num2 == 0.0) return false;
        this->num2 = num2;
        return true;
    }

    double add()
    {
        return num1 + num2;
    }

    double multiply()
    {
        return num1 * num2;
    }

    double subtract_1_2()
    {
        return num1 - num2;
    }

    double subtract_2_1()
    {
        return num2 - num1;
    }

    double divide_1_2()
    {
        return num1 / num2;
    }

    double divide_2_1()
    {
        return num2 / num1;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    Calculator calc;
    double num1, num2;

	while (true)
    {
        std::cout << "Введите первое число: ";
        std::cin >> num1;

        while (!calc.setNum1(num1))
        {
            std::cout << "Число не может быть равно 0. Повторите ввод: ";
            std::cin >> num1;
        }

        std::cout << "Введите второе число: ";
        std::cin >> num2;

        while (!calc.setNum2 (num2))
        {
            std::cout << "Число не может быть равно 0. Повторите ввод: ";
            std::cin >> num2;
        }

        std::cout << "num1 + num2 = " << calc.add() << "\n";
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << "\n";
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << "\n";
        std::cout << "num1 * num2 = " << calc.multiply() << "\n";
        std::cout << "num1 / num2 = " << calc.divide_1_2() << "\n";
        std::cout << "num2 / num1 = " << calc.divide_2_1() << "\n";
       
    }
}
