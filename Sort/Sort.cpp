#include <iostream>
#include <chrono>
#include <random>

void printNElmets(double A[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << A[i] << " | ";
    }
    std::cout << '\n';
}

void insertionSort(double A[], int n) {
    
    double key;
    int i;

    for (int j = 1; j < n; ++j) {
        key = A[j];
        i = j - 1;
        while ((i >= 0) && A[i] > key) {
            A[i + 1] = A[i];
           --i;
        }
        A[i + 1] = key;
    }
}

void merge(double A[], double temp[], int p, int q, int r) {

    int i = p;
    int j = q + 1;
    int k = p;

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
            temp[k++] = A[i++];
        else
            temp[k++] = A[j++];
    }

    while (i <= q)
        temp[k++] = A[i++];

    while (j <= r)
        temp[k++] = A[j++];

    for (int x = p; x <= r; ++x)
        A[x] = temp[x];
}

void mergeSort(double A[], double temp[], int p, int r) {
    int q;

    if (p < r) {
        q = (p + r) / 2;
        mergeSort(A, temp, p, q);
        mergeSort(A, temp,  q + 1, r);
        merge(A, temp, p, q, r);
    }
}

int main()
{
    constexpr int n = 128; //numbers elements array
    constexpr int iterations = 10; // iterations

    double total = 0.0; //time


    double* A = new double[n];
    double* B = new double[n];
    double* temp = new double[n];

    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < n; ++i)
        A[i] = dist(gen);

    //10 first elements
    std::cout << "Source array:" << "\n";
    printNElmets(A, 10);

    for (int iteration = 0; iteration < iterations; ++iteration) {
        std::copy(A, A + n, B);

        auto start = std::chrono::steady_clock::now();

        insertionSort(B, n);

        auto end = std::chrono::steady_clock::now();

        total += std::chrono::duration<double, std::milli>(
            end - start).count();
    }

    std::cout << "Dist array:" << "\n";
    printNElmets(B, 10);
    std::cout << "Time insSort: " << total/iterations << " ms\n";

    total = 0.0;

    for (int iteration = 0; iteration < iterations; ++iteration) {
        std::copy(A, A + n, B);
        auto start = std::chrono::steady_clock::now();

        mergeSort(B, temp, 0, n - 1);

        auto end = std::chrono::steady_clock::now();

        total += std::chrono::duration<double, std::milli>(
            end - start).count();
    }
    

    std::cout << "Dist array:" << "\n";
    printNElmets(B, 10);
    std::cout << "Time margeSort: " << total/iterations << " ms\n";

    delete[] A;
    delete[] B;
    delete[] temp;

    return EXIT_SUCCESS;
}