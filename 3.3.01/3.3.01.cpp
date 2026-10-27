#include <iostream>
#include <vector>

void printArr(std::vector<int> arr) {
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
    std::cout << '\n';
}

void merge(std::vector<int>& arr, int lo, int mid, int hi) {
    std::vector<int> temp;
    temp.reserve(hi - lo + 1);

    int i = lo;
    int j = mid + 1;

    while (i <= mid && j <= hi) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }

    while (i <= mid) temp.push_back(arr[i++]);

    while (j <= hi) temp.push_back(arr[j++]);

    for (rsize_t k = 0; k < temp.size(); ++k)
        arr[lo + k] = temp[k];
}

void merge_sort(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi) return;

    int mid = lo + (hi - lo) / 2;
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);

}

int main()
{
    std::cout << "Merge sort\n";

    std::vector<int> arr1{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    std::vector<int> arr2{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    std::vector<int> arr3{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };

    std::cout << "Source array1: ";
    printArr(arr1);

    merge_sort(arr1, 0, static_cast<int>(arr1.size()) - 1);

    std::cout << "Sort array1:   ";
    printArr(arr1);

    std::cout << "Source array2: ";
    printArr(arr2);

    merge_sort(arr2, 0, static_cast<int>(arr2.size()) - 1);

    std::cout << "Sort array2:   ";
    printArr(arr2);


    std::cout << "Source array3: ";
    printArr(arr3);

    merge_sort(arr3, 0, static_cast<int>(arr3.size()) - 1);

    std::cout << "Sort array3:   ";
    printArr(arr3);
}

