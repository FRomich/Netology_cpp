#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int firstNumber, secondNumber;
    std::string sign, firstNemberText, secondNumberText;

    std::string unit[] = {
        "ноль", "один", "два", "три", "четыре",
        "пять", "шесть", "семь", "восемь", "девять",
        "десять", "одиннадцать", "двенадцать", "тринадцать",
        "четырнадцать", "пятнадцать", "шестнадцать",
        "семнадцать", "восемнадцать", "девятнадцать"
    };
    std::string tens[] =
    {
        "", "", "двадцать", "тридцать", "сорок",
        "пятьдесят", "шестьдесят", "семьдесят",
        "восемьдесят", "девяносто"
    };


    std::cout << "Введите целое число: ";
    std::cin >> firstNumber;
    std::cout << "Введите целое число: ";
    std::cin >> secondNumber;

    if (firstNumber >= 100 || firstNumber <= -100 || secondNumber >= 100 || secondNumber <= -100)
    {
        std::cout << "Ошибка! Одно из чисел вне диапазона!";
    }
    else
    {
	    sign = (firstNumber > secondNumber)
    		? "больше чем"
    		: (firstNumber == secondNumber) ? "равно" : "меньше чем";
        if (firstNumber < 0) firstNemberText = "минус ";
        if (secondNumber < 0) secondNumberText = "минус ";

	    if (abs(firstNumber) < 20)
	    {
            firstNemberText += unit[abs(firstNumber)];
	    }
    	else
	    {
            firstNemberText += (abs(firstNumber) % 10 == 0)
    			? tens[abs(firstNumber) / 10]
    			: tens[abs(firstNumber) / 10] + " " + unit[abs(firstNumber) % 10];
	    }

        if (abs(secondNumber) < 20)
        {
            secondNumberText += unit[abs(secondNumber)];
        }
        else
        {
            secondNumberText += (abs(secondNumber) % 10 == 0)
                ? tens[abs(secondNumber) / 10]
                : tens[abs(secondNumber) / 10] + " " + unit[abs(secondNumber) % 10];
        }


        std::cout << firstNemberText << " " << sign << " " << secondNumberText;
    }

}
