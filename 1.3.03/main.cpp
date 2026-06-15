#include <iostream>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string gender;
    std::string zodiacSign;
    int age;

    std::cout << "Введите пол: ";
    std::cin >> gender;
    std::cout << "Введите знак зодиака: ";
    std::cin >> zodiacSign;
    std::cout << "Введите возраст: ";
    std::cin >> age;

    if (gender == "м" && (zodiacSign == "рак" || zodiacSign == "скорпион" || zodiacSign == "рыбы") && age < 40)
    {
        std::cout << "Сегодня очень плодотворный день. Можно добиться того, что прежде казалось почти невозможным.\n";
    }
    else if (gender == "ж" && (zodiacSign == "телец" || zodiacSign == "дева" || zodiacSign == "козерог") && age >= 15 && age <= 30)
    {
        std::cout << "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.\n";
    	std::cout << "Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех.\n";
    }
    else std::cout << "Гороскоп для вас находится в разработке. Приходите чуточку позже ;)\n";
}
