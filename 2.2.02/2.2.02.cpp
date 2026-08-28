
#include <iostream>

class Counter
{
private:
    int count;
public:

	Counter() : count(1) {}
	Counter(int count) : count(count) {}


	void Inc()
	{
		++count;
	}

	void Decr()
	{
		--count;
	}

	void Print()
	{
		std::cout << "Сейчас счетчик: " << count << "\n";
	} 
};

int main()
{
    setlocale(LC_ALL, "Russian");
	
	std::string ans{};
	std::string cmd{};
	Counter counter;

	std::cout << "Вы хотите указать начальное значение счётчика? Введите y или n:";
	std::cin >> ans;

    while (ans != "y" && ans != "n")
    {
	    std::cout << "Некорректный ввод. Введите y или n:";
		std::cin >> ans;
    }

	if (ans == "y")
	{
		int count;
		std::cout << "Введите начальное значение счётчика:";
		std::cin >> count;
		counter = Counter(count);
	}
	do
	{
		std::cout << "Введите команду('+', '-', '=' или 'x'): ";
		std::cin >> cmd;

		if (cmd == "+")
			counter.Inc();
		else if (cmd == "-")
			counter.Decr();
		else if (cmd == "=")
			counter.Print();
		else if (cmd != "x")
			std::cout << "Неизвестная команда\n";

	} while (cmd != "x");

	std::cout << "До свидания!\n";
}

