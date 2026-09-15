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
		catch (...)
		{
			std::cout << "Вы ввели слово запретной длины! До свидания\n";
			return 1;
		}
		std::cout << "Длина слова \"" << str << "\" равна " << length << "\n";
	}
}

int function(std::string str, int forbidden_length)
{
	if (str.length() == forbidden_length) throw "forbidden length";
	return static_cast<int>(str.length());
}