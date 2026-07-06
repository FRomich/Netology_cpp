#include <iostream>

void print(int* array, int sizeArray)
{
	for (int i = 0; i < sizeArray; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	int array1[]{1, 2, 3, 4, 5, 6, 7, 8, 9};

	print(array1, std::size(array1));

	int array2[]{1, 2, 36, 4, 8, 90, 7};

	print(array2, std::size(array2));

	int array3[]{9, 8, 7, 6, 5, 4, 3, 2, 1};

	print(array3, std::size(array3));
}

