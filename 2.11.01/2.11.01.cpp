#include <assert.h>
#include <iostream>

#include "extended_array.h"

void test1()
{
	ExtArray<int> v1{};

	assert(v1.mean() == 0);
	std::cout << "Mean test OK\n";

	assert(v1.median() == 0);
	std::cout << "Median test OK\n";

	assert(v1.mode().second == 0);
	std::cout << "Mode test OK\n";
}

void test2()
{
	ExtArray<int> v2{4, 2, 7, 3, -5, 0, -3, 1};

	try
	{
		v2.mean(5, 3);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Mean range test OK: " << e.what() << '\n';
	}

	try
	{
		v2.mean(3, 3);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Mean range test OK: " << e.what() << '\n';
	}

	try
	{
		v2.mean(10, 11);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Mean range test OK: " << e.what() << '\n';
	}

	assert(v2.mean(3,6) == 1.25);
	std::cout << "Mean range test OK\n";
}

void test3()
{
	ExtArray<double> v3{4.0, 2.2, 7.5, 3};

	try
	{
		v3.checkSum();
	}
	catch (const std::bad_typeid& e)
	{
		std::cout << "CheckSum type test OK: " << e.what() << '\n';
	}

	ExtArray<int> v4{4, 2, 5, 3};

	try
	{
		v4.checkSum();
	}
	catch (const std::logic_error& e)
	{
 		std::cout << "CheckSum test OK: " << e.what() << '\n';
	}

	ExtArray<int> v5{ 1, 0, 1, 1, 0 };

	assert(v5.checkSum() == 3);
	std::cout << "CheckSum test OK\n";
}

int main()
{
    test1();
	test2();
	test3();
}
