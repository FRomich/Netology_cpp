#include <iostream>

enum class months
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main()
{
	setlocale(LC_ALL, "Russian");

	int numberMonths = -1;

	do
	{
		std::cout << "Введите номер месяца (для выхода введите 0):";
		std::cin >> numberMonths;

		if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Ошибка: необходимо ввести число.\n";
            numberMonths = -1;
			continue;
		}

		if (numberMonths < 0 || numberMonths > 12)
		{
			std::cout << "Ошибка: Неправильный номер!\n";
            continue;
		}

		months month = static_cast<months>(numberMonths);

        switch (month)
        {
        case months::January:
            std::cout << "Январь\n";
            break;

        case months::February:
            std::cout << "Февраль\n";
            break;

        case months::March:
            std::cout << "Март\n";
            break;

        case months::April:
            std::cout << "Апрель\n";
            break;

        case months::May:
            std::cout << "Май\n";
            break;

        case months::June:
            std::cout << "Июнь\n";
            break;

        case months::July:
            std::cout << "Июль\n";
            break;

        case months::August:
            std::cout << "Август\n";
            break;

        case months::September:
            std::cout << "Сентябрь\n";
            break;

        case months::October:
            std::cout << "Октябрь\n";
            break;

        case months::November:
            std::cout << "Ноябрь\n";
            break;

        case months::December:
            std::cout << "Декабрь\n";
            break;
        }

	} while (numberMonths != 0);
    std::cout << "До свидания\n";
}
