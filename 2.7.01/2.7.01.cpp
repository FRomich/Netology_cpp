#include <iostream>

int function(std::string str, int forbidden_length);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int forbidden, length;
	std::string str;

    std::cout << "Введите запретную длину: ";
	std::cin >> forbidden;
	while (true)
	{
		std::cout << "Введите слово: ";
		std::cin >> str;
		try
		{
			length = function(str, forbidden);
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << e.what() << " До свидания\n";
			return 1;
		}
		std::cout << "Длина слова \"" << str << "\" равна " << length << "\n";
	}
}

int function(std::string str, int forbidden_length)
{
	if (str.length() == forbidden_length) throw std::invalid_argument("Вы ввели слово запретной длины!");
	return static_cast<int>(str.length());
}