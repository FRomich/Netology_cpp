#pragma once
#include <utility>
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class ExtArray
{
private:
	std::vector<T> extended_array;
	size_t _size;
public:
	ExtArray(std::initializer_list<T> l) : extended_array(l)
	{
		_size = l.size();
	}

	ExtArray(int size) : _size(size)
	{
		extended_array.resize(_size);
	}

	T& operator[](size_t index)
	{
		return extended_array[index];
	}

	size_t size()
	{
		return _size;
	}

	double mean()
	{
		if (_size == 0) return 0;

		double sum = 0;

		for (size_t i = 0; i < _size; i++)
		{
			sum += extended_array[i];
		}
		return sum / _size;
	}

	double mean(size_t start, size_t end)
	{
		if (_size == 0) return 0;

		if (start > end)  throw std::invalid_argument("start > end");
		if (end > _size)  throw std::invalid_argument("end > sizeArray");
		if (start == end) throw std::invalid_argument("empty range");

		double sum = 0;

		for (size_t i = start - 1; i < end; ++i)
		{
			sum += extended_array[i];
		}

		return sum / (end - start + 1);
	}

	double median()
	{
		if (_size == 0) return 0;

		std::vector<T> temp_array;
		std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
		std::sort(temp_array.begin(), temp_array.end());
		if (_size % 2 == 1)
		{
			return temp_array[_size / 2];
		}
		return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
	}

	std::pair<T, int> mode()
	{

		if (_size == 0) return std::pair<T, int>(0, 0);

		T max = extended_array[0];
		int rmax = 0;

		for (int i = 0; i < _size; ++i)
		{
			int count = 0;

			for (int j = i; j < _size; ++j)
			{
				if (extended_array[j] == extended_array[i])
				{
					++count;
				}
			}

			if (count > rmax)
			{
				rmax = count;
				max = extended_array[i];
			}
		}

		return { max, rmax };
	}

	int checkSum()
	{
		int sum = 0;

		if (!std::is_same_v<T, int> && !std::is_same_v<T, bool>)
		{
			throw std::bad_typeid();
		}

		for (int i = 0; i < _size; ++i)
		{
			if (extended_array[i] != 1 && extended_array[i] != 0)
				throw std::logic_error("Contains an invalid character");

			if (extended_array[i] == 1)
			{
				++sum;
			}
		}
		return sum;
	}
};
