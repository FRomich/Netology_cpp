#include "MyCalc.h"

#include <cmath>

double my_calc::sum(double val1, double val2)
{
	return val1 + val2;
}

double my_calc::diff(double val1, double val2)
{
	return val1 - val2;
}

double my_calc::mult(double val1, double val2)
{
	return val1 * val2;
}

double my_calc::div(double val1, double val2)
{
	return val1 / val2;
}

double my_calc::pow(double val1, int val2)
{
	return std::pow(val1, val2);
}
