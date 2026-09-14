#include "Counter.h"

#include <iostream>

Counter::Counter() : count(1) {}
Counter::Counter(int count) : count(count) {}


void Counter::inc()
{
	++count;
}

void Counter::decr()
{
	--count;
}

void Counter::print()
{
	std::cout << "Сейчас счетчик: " << count << "\n";
}

