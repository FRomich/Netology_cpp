#pragma once

class Counter
{
private:
	int count;
public:

	Counter();
	Counter(int count);


	void inc();
	void decr();
	void print();
	
};
