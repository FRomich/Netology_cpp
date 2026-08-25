#include <iostream>
#include <string>

struct Address
{
    std::string town;
    std::string street;
    int numberHouse;
    int numberApartment;
    int postCode;
};

void printAddress(const Address& address)
{
    std::cout << "Город: " << address.town << "\n";
    std::cout << "Улица: " << address.street << "\n";
    std::cout << "Номер дома: " << address.numberHouse << "\n";
    std::cout << "Номер квартиры: " << address.numberApartment << "\n";
    std::cout << "Индекс: " << address.postCode << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Address firstAddress{
        "Москва", "Арбат", 12, 8, 123456};
    printAddress(firstAddress);

    std::cout << "\n";

    Address secondAddress{
        "Ижевск", "Пушкина",  59, 43,  953769 };
    printAddress(secondAddress);

}
