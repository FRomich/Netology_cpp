#include "Test_boost.h"

#include <boost/tokenizer.hpp>

using namespace std;

int main()
{
	std::string str = ";;Hello|world||-foo--bar;yow;baz|";
	boost::char_separator<char> sep("-;|");
	boost::tokenizer<boost::char_separator<char>> tokens(str, sep);
	for (auto tok : tokens)
		std::cout << "<" << tok << "> ";

	return 0;
}
