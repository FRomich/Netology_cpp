#include <iostream>
#include <vector>

int NumElementsLarge(std::vector<int> numbers, int number) {
    int left = 0;
    int rigth = numbers.size();

     while (left < rigth) {
        int middle = (left + rigth) / 2;

        if (numbers[middle] <= number) {
            left = middle + 1;
        }
        else rigth = middle;
     }
    return numbers.size() - left;
}
 
int main()
{
    setlocale(LC_ALL, "Russian");

    int num;

    std::vector<int> numbersSort = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };

    std::cout << "Введите точку отсчёта : ";
    std::cin >> num;
    
    std::cout << "Количество элементов в массиве больших, чем " << num << ": "
        << NumElementsLarge(numbersSort, num);

}

