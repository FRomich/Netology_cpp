#include <iostream>


void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    
    if (actual_size < 1) return;

    std::cout << "Dynamic array: ";

    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size)
            std::cout << arr[i] << " ";
        else
            std::cout << "_ ";
    }

    std::cout << '\n';

}

void append_to_dynamic_array(int*& arr, int &logical_size, int &actual_size, const int  item) {
    
    if (logical_size == actual_size) {
       int* arrNew = new int[actual_size * 2];
       
       for (int i = 0; i < logical_size; ++i) {
           arrNew[i] = arr[i];

       }
       delete[] arr;
       arr = arrNew;
       actual_size *= 2;
    }
    arr[(logical_size)++] = item;
}

void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
    
    if (logical_size == 0)
        return;

    for (int i = 0; i < logical_size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    --logical_size;

    if (logical_size > 0 && logical_size <= actual_size / 3)
    {
        int* arrNew = new int[actual_size / 3];

        for (int i = 0; i < logical_size; ++i) {
            arrNew[i] = arr[i];
        }
        delete[] arr;
        arr = arrNew;
        actual_size /= 3;
    }
}

int main()
{
    int actual_size, logical_size, item;

    std::cout << "Enter the actual size of the array: ";
    std::cin >> actual_size;
    std::cout << "Enter the logical size of the array: ";
    std::cin >> logical_size;

    if (logical_size > actual_size) {
        std::cout << "Error! The logical size of an array cannot exceed its actual size!";
        return EXIT_FAILURE;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        std::cout << "Enter arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    while (true) {
        std::cout << "Enter an item to add, or 0 to exit: ";
        std::cin >> item;

        if (item == 0) break;

        append_to_dynamic_array(arr, logical_size, actual_size, item);
    }

    print_dynamic_array(arr, logical_size, actual_size);

    while (true) {
        std::cout << "Remove the first element (1 - yes): ";
        std::cin >> item;

        if (item != 1) break;

        if (logical_size == 0) {
            std::cout << "It is impossible to remove the first element, as the array is empty. Goodbye!";
            delete[] arr;
            return EXIT_SUCCESS;
        }
        remove_dynamic_array_head(arr, logical_size, actual_size);

        print_dynamic_array(arr, logical_size, actual_size);
    }

    delete[] arr;

    return EXIT_SUCCESS;

}

