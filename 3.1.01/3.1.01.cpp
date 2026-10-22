#include <iostream>

int calc(int* arr, int size)
{
    int ans = 0;
    for (int i = 1; i < size; i++)
    {
        ans += arr[i] - arr[i - 1];
    }
    return ans;
}

int main()
{
    std::cout << "Hello World!\n";
}
