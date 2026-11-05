#include <iostream>
#include "Heap.h"

int main()
{
	std::string arr = "16 11 9 10 5 6 8 1 2 4";
	int currentIdx = 0;
	int nextIdx = 0;
	int command = 0;

	std::cout << "Source array: " << arr <<'\n';

	Heap* heap = new Heap(arr);

	std::cout << "Pyramid: \n";

	heap->print_pyramid();

	std::cout << "You are here: ";
	heap->printFromIdx(currentIdx);

	do
	{
		std::cout << "Enter a command (1 - up, 2 - left; 3 - right, 0 - exit) :";
		std::cin >> command;

		switch (command)
		{
		case 1: 
			if (currentIdx == 0) {
				std::cout << "Error. Parent missing\n";
				break;
			}
			currentIdx = heap->parent_index(currentIdx);
			std::cout << "Ok\n";
			break;
		case 2:
			nextIdx = heap->left_index(currentIdx);

			if (nextIdx > heap->getSize()) {
				std::cout << "Error! Left child is missing\n";
				break;
			}
			currentIdx = nextIdx;
			std::cout << "Ok\n";
			break;
		case 3:
			nextIdx = heap->right_index(currentIdx);

			if (nextIdx > heap->getSize()) {
				std::cout << "Error! Right child is missing\n";
				break;
			}
			currentIdx = nextIdx;
			std::cout << "Ok\n";
			break;
		default:
			break;
		}

		std::cout << "You are here: ";
		heap->printFromIdx(currentIdx);
	} while (command != 0);

	std::cout << "Bye\n";

	delete heap;
}


