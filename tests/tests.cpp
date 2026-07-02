#include <iostream>

void foo ()
{
	static int i = 0;
	std::cout << i << "\n";
	i++;
}

int main()
{
	
	std::cout << "first call: ";
	foo();
	std::cout << "second call: ";
	foo();
	std::cout << "third call: ";
	foo();
}
