#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

class Address
{
private:
    std::string town;
    std::string street;
    int numberHouse;
    int numberApartment;
public:
    Address(const std::string& town, const std::string& street, int numberHouse, int numberApartment) :
        town(town),
        street(street),
        numberHouse(numberHouse),
        numberApartment(numberApartment)
    {
    }

    std::string getOutputAddress() const
    {
        return town + ", "
            + street + ", "
            + std::to_string(numberHouse) + ", "
            + std::to_string(numberApartment) + "\n";
    }

    const std::string& getTown() const
    {
        return town;
    }
};

void sort(Address** addresses, int size)
{
    std::sort(addresses, addresses + size,
        [](const Address* a, const Address* b)
        {
            return a->getTown() < b->getTown();
        });
}

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string inputPath = "in.txt";
    std::string outputPath = "out.txt";
    unsigned count;

    std::ifstream inFile(inputPath);
    if (!inFile)
    {
        std::cerr << "Ошибка: не удалось открыть файл: " << inputPath << '\n';
        return 1;
    }

    if (!(inFile >> count) || count == 0)
    {
        std::cerr << "Некорректное количество адресов\n";
        return 1;
    }

    Address** addresses = new Address * [count];

    for (unsigned i = 0; i < count; ++i)
    {
        std::string town;
        std::string street;
        int numberHouse;
        int numberApartment;

        inFile >> town >> street >> numberHouse >> numberApartment;

        addresses[i] = new Address(
            town,
            street,
            numberHouse,
            numberApartment
        );
    }

    inFile.close();

    sort(addresses, count);

    std::ofstream outFile(outputPath);

    outFile << count << "\n";

    for (unsigned i = 0 ; i < count; ++i)
    {
        outFile << addresses[i]->getOutputAddress();
    }

    outFile.close();

    for (unsigned i = 0; i < count; ++i)
    {
        delete addresses[i];
    }

    delete[] addresses;

    std::cout << "Данные отсортированы и записаны в файл: " << outputPath << "\n";
}

