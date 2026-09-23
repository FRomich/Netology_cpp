#include <iostream>
#include <fstream>

#include "ProcessingFreelancers.h"

struct Test
{
    std::string name;
    std::string description;
};

std::vector<Test> tests =
{
    {"test1", "Группировка стран и сортировка по количеству"},
    {"test2", "Граничные значения года рождения"},
    {"test3", "Недопустимые символы в фамилии"},
    {"test4", "Граничная длина фамилии"},
    {"test5", "Валидация названия страны"},
    {"test6", "Валидация ProjectID"},
    {"test7", "Пробелы вокруг разделителей"},
    {"test8", "Сортировка при одинаковом количестве"},
    {"test9", "Нет валидных записей"}
};

std::vector<std::string> readfile(const std::string& filename)
{
    std::ifstream file(filename);

    std::vector<std::string> result;
    std::string line;

    while (std::getline(file, line))
    {
        result.push_back(line);
    }

    return result;

}

int main()
{
    setlocale(LC_ALL, "russian");

    ProcessingFreelancers PF;

    for (size_t i = 0; i <= tests.size() - 1; ++i)
    {
        std::string inputFile =  "tests/" + tests[i].name + ".txt";
        std::string expectedFile = "tests/" + tests[i].name + "_expected.txt";

        auto input = readfile(inputFile);
        auto expect = readfile(expectedFile);
        auto actual = PF.generate_report(input);

        std::cout << tests[i].name << ": "
            << tests[i].description << " — ";

        if (actual == expect)
        {
            std::cout << "OK\n";
        }
        else
        {
            std::cerr << "FAILED\n";
        	std::cout << "Expected: \n";
            for (const auto& str : expect)
            {
                std::cout << str << "\n";
            }

            std::cout << "Actual: \n";
            for (const auto& str : actual)
            {
                std::cout << str << "\n";
            }

        }
    }

    return EXIT_SUCCESS;
}
