#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

int partition (std::vector<int>& arr, int lo, int hi){
    int pivot = arr[lo + (hi - lo) / 2];
    int i = lo - 1;
    int j = hi + 1;

    while (true) {
        do {
            ++i;
        } while (arr[i] < pivot);

        do {
            --j;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        std::swap(arr[i], arr[j]);
    }
}

void quick_sort(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi) return;

    int p = partition(arr, lo, hi);

    quick_sort(arr, lo, p);
    quick_sort(arr, p + 1, hi);
}

int main()
{
    std::cout << "Quick sort\n";

    std::vector<int> arr1{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    std::vector<int> arr2{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    std::vector<int> arr3{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    std::cout << "Source array1: ";
    printArr(arr1);

    quick_sort(arr1, 0, static_cast<int>(arr1.size()) - 1);

    std::cout << "Sort array1:   ";
    printArr(arr1);

    std::cout << "Source array2: ";
    printArr(arr2);

    quick_sort(arr2, 0, static_cast<int>(arr2.size()) - 1);

    std::cout << "Sort array2:   ";
    printArr(arr2);


    std::cout << "Source array3: ";
    printArr(arr3);

    quick_sort(arr3, 0, static_cast<int>(arr3.size()) - 1);

    std::cout << "Sort array3:   ";
    printArr(arr3);
}

