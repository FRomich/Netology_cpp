#pragma once
#include <vector>
#include <string>
#include <sstream>

class Heap
{
public:
	Heap(std::string);
	~Heap();
	int root();
	int left_index(int);
	int right_index(int);
	int parent_index(int);
	int from_index(int);
	void printFromIdx(int);
	int level(int);
	void print_pyramid();
	int getSize();

	void print_pyramid_DFS();
	void print_pyramid_BFS();
	void printEl(int, bool, int);
	

private:
	std::vector<int> data;
};




