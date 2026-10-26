#include <iostream>
#include <vector>

int cacheFib(int n) {
    if (n <= 1) return n;

    static std::vector<int> cache(2, -1);
    cache[0] = 0;
    cache[1] = 1;

    if (n >= static_cast<int>(cache.size())) {
        cache.resize(n + 1, -1);
    }

    if (cache[n] != -1) {
        return cache[n];
    }

    cache[n] = cacheFib(n - 1) + cacheFib(n - 2);
    return cache[n];
}

int main()
{
    int n = 10;
    std::cout << "fib(" << n << ") = " << cacheFib(n);
}

