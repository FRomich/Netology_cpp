#include <iostream>

#include "simple-bench.h"

/// <summary>
/// https://projecteuler.net/archives
/// </summary>

namespace 
{

	/// <summary>
	/// the sum of n odd squares
	/// registration
	/// </summary>
	/// <param name="n"></param>
	/// <returns></returns>
	/// 
	static unsigned long long sumSQ (int n)
	{
        unsigned long long result = 0;

        for (int i = 1; i < n; ++i)
        {
            if ((i * i) % 2 != 0) result += 1ULL * i * i;
        }

        return result;
	}
	
    /// <summary>
    /// sum of all the multiples of  or  below n
    /// #1
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
	
    static unsigned long long sumMultiples3or5(int n)
	{
        unsigned long long result = 0;

        for (int i = 1; i < n; ++i)
        {
	        if (i % 3 == 0 || i % 5 == 0)
	        {
                result += i;
	        }
        }

        return  result;
	}

    /// <summary>
    /// the sum of the even-valued fibonacci terms below n
    /// #2
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    static unsigned long long sumFibEven(int n)
	{
        
        int fibPrv = 1;
        int fibNext = 2;
        int tmp;
        unsigned long long result = 0;

        while (true)
        {
            if (fibNext > n) break;

            if (fibNext % 2 == 0)
        	result += fibNext;

            tmp = fibNext;
            fibNext += fibPrv;
            fibPrv = tmp;
        }

        return result;
	}

    /// <summary>
    /// the largest prime factor of the number
    /// #3
    /// </summary>
    /// <param name="n"></param>
    /// <returns></returns>
    static unsigned long long largestPrimeFct(unsigned long long n)
	{
        unsigned long long result = 1;
        unsigned long long sqrtN = static_cast<unsigned long long>(sqrt(n));

        for (unsigned long long i = sqrtN; i >= 5; --i)
        {
	        if (n % i == 0)
	        {
                result = i;
                unsigned long long sqrtI = static_cast<unsigned long long>(sqrt(i));

	        	for (unsigned long long j = sqrtI; j > 1; --j)
                {
	                if (i % j == 0)
	                {
                        result = 1;
		                break;
	                }
                }

                if (result != 1) break;
	        }
        }

        return result;
	}


    /// <summary>
    /// the largest palindrome made from the product of two 3-digit numbers
    /// #4
    /// </summary>
    /// <returns></returns>
    static int palindromeProdTwo3dgt()
	{
        for (int i = 999 * 999; i > 0; --i)
        {
            if (i % 10 == 0) continue;

            int reversedHalf = 0;
            int tmp = i;

            while (tmp > reversedHalf)
            {
                reversedHalf = reversedHalf * 10 + tmp % 10;
                tmp /= 10;
            }
            if (tmp == reversedHalf || tmp == reversedHalf / 10)
            {
                for (int a = 999; a > 99; --a)
                {
	                if (i % a == 0)
	                {
                        int b = i / a;

                        if (b > 99 && b <= 999)
                            return i;
	                }
                }
            }
        }
        return 0;
	}

}

int main()
{
    struct timespec time1, time2;

    int countSQ = 667000;
    int countMult = 1000;
    int countFib = 4000000;
    unsigned long long number = 600851475143;
#if 0
    
    std::cout << "The sum of " << countSQ << " odd squares:" << sumSQ(countSQ) << "\n";
    std::cout << "The sum of multiples of 3 or 5 below " << countMult << ": " << sumMultiples3or5(countMult) << "\n";
    std::cout << "The sum of the even-valued fibonacci terms below " << countFib << ": " << sumFibEven(countFib) << "\n";
    std::cout << "The largest prime factor of the number " << number << ": " << largestPrimeFct(number) << "\n";
    std::cout << "The largest palindrome made from the product of two 3-digit numbers: " << palindromeProdTwo3dgt() << "\n";
}
#endif

	simple_gettime(&time1);
    for (int i = 0; i < 100; ++i) 
    {
        palindromeProdTwo3dgt();
    }
    simple_gettime(&time2);
    std::cout << diff(time1, time2) << "\n";

    std::cout << "the largest palindrome made from the product of two 3-digit numbers: " << palindromeProdTwo3dgt() << "\n";
}

