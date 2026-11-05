#include "Heap.h"
#include <iostream>
#include <queue>
#include <utility>

Heap::Heap(std::string str)
{
	std::stringstream ss(str);
	int value;

	while (ss >> value)
	{
		data.push_back(value);
	}
}

Heap::~Heap()
{
}

int Heap::root() 
{
	return data[0];
}

int Heap::left_index(int parent_index) 
{
	return 2 * parent_index + 1;
} 

int Heap::right_index(int parent_index)
{
	return 2 * parent_index + 2;
}

int Heap::parent_index(int child_index)
{
	return (child_index - 1) / 2;
}

int Heap::from_index(int idx)
{
	return data[idx];
}

int Heap::level(int index)
{
    return static_cast<int>(std::log2(index + 1));
}

void Heap::printFromIdx(int idx)
{
    if (idx == 0) {
        std::cout << level(idx) << " root " << from_index(idx) << '\n';
    }
    else if (idx % 2 != 0) {
        std::cout << level(idx) << " left(" << from_index(parent_index(idx))
            << ") " << from_index(idx) << '\n';
    }
    else
        std::cout << level(idx) << " right(" << from_index(parent_index(idx))
        << ") " << from_index(idx) << '\n';
}

int Heap::getSize() 
{
    return data.size();
};

void Heap::print_pyramid()
{
    for (size_t i = 0; i < data.size(); ++i) {
        printFromIdx(i);
    }
}

void  Heap::printEl(int idx, bool left, int level)
{
 	if (idx >= data.size()) return;

	if (idx == 0) {
		std::cout << level << " root " << from_index(idx) << '\n';
	}
	 
	else if (left) {
		std::cout << level << " left(" << from_index(parent_index(idx))
			<< ") " << from_index(idx) << '\n';
	}
	else 
		std::cout << level << " right(" << from_index(parent_index(idx))
		<< ") " << from_index(idx) << '\n';

	printEl(left_index(idx), true, level + 1);
	printEl(right_index(idx), false, level + 1);
}

void Heap::print_pyramid_DFS()
{
	printEl(0,false, 0);
}

void Heap::print_pyramid_BFS()
{
    if (data.empty()) return;

    std::queue<std::pair<int, int>> q;

    q.push({ 0, 0 });

    while (!q.empty())
    {
        std::pair<int, int> element = q.front();

        int idx = element.first;
        int level = element.second;

        q.pop();

        if (idx == 0)
        {
            std::cout << level << " root "
                << from_index(idx) << '\n';
        }
        else
        {
            int parent = parent_index(idx);

            if (idx == left_index(parent))
            {
                std::cout << level << " left("
                    << from_index(parent) << ") "
                    << from_index(idx) << '\n';
            }
            else
            {
                std::cout << level << " right("
                    << from_index(parent) << ") "
                    << from_index(idx) << '\n';
            }
        }

        int left = left_index(idx);

        if (left < data.size())
        {
            q.push({ left, level + 1 });
        }

        int right = right_index(idx);

        if (right < data.size())
        {
            q.push({ right, level + 1 });
        }
    }
}
