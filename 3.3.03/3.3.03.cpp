#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

void count_sort(std::vector<int>& arr) {
    if (arr.empty()) return;

    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());

    std::vector<int>count(max - min + 1, 0);

    for (int x : arr) ++count[x - min];
    
    size_t idx = 0;
    for (int i = 0; i <= max - min; ++i) {
        while (count[i] > 0) {
            arr[idx++] = i + min;
            --count[i];
        }
    }
}

int main()
{
    std::cout << "Quick sort\n";

    std::vector<int> arr1{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    std::vector<int> arr2{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11,
        16, 22, 23, 16 };
    std::vector<int> arr3{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24,
        23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };


    
    std::cout << "Source array1: ";
    printArr(arr1);

    count_sort(arr1);

    std::cout << "Sort array1:   ";
    printArr(arr1);

    std::cout << "Source array2: ";
    printArr(arr2);

    count_sort(arr2);

    std::cout << "Sort array2:   ";
    printArr(arr2);


    std::cout << "Source array3: ";
    printArr(arr3);

    count_sort(arr3);

    std::cout << "Sort array3:   ";
    printArr(arr3);
}

