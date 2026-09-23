#include "ProcessingFreelancers.h"

#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string>
ProcessingFreelancers::generate_report(const std::vector<std::string>& input) const
{
    std::vector<std::string> result;
    std::map<std::string, int> countries;

    for (const auto& str : input) {

        std::stringstream ss(str);
        
        auto getFiels = [](std::stringstream& ss)
        {
			std::string field;
            std::getline(ss, field, ';');

            size_t begin = field.find_first_not_of(' ');
            size_t end = field.find_last_not_of(' ');

            if (begin == std::string::npos)
            {
                return std::string{};
            }

            return field.substr(begin, end - begin + 1);
				
        };

        std::string field1 = getFiels(ss);
        std::string field2 = getFiels(ss);
        std::string field3 = getFiels(ss);
        std::string field4 = getFiels(ss);
        

        //check field1
        if (field1.length() < 1 || field1.length() > 40) continue;

        bool invalid = false;

        for (char c : field1) {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                invalid = true;
                break;
            }
        }

        if (invalid) continue;

        //check field2

        int year = std::stoi(field2);
        if (year < 1960 || year > 2007) continue;

        //check field3
        if (field3.length() < 2 || field3.length() > 40) continue;

        for (char c : field3) {
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                invalid = true;
                break;
            }
        }

        if (invalid || field3 == "none") continue;

        //check field4

        if (field4.length() != 5) continue;

        if (!((field4[0] >= 'A' && field4[0] <= 'Z'))) continue;
        if (!((field4[1] >= 'A' && field4[1] <= 'Z'))) continue;
        if (!((field4[2] >= '0' && field4[2] <= '7'))) continue;
        if (!((field4[3] >= '0' && field4[3] <= '7'))) continue;
        if (!((field4[4] >= '0' && field4[4] <= '7'))) continue;

       countries[field3]++;
    }

    std::vector<std::pair<std::string, int>> sortedCountries(
        countries.begin(), countries.end()
    );

    std::sort(sortedCountries.begin(), sortedCountries.end(),
        [](const auto& a, const auto& b)
        {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first < b.first;
        });

    for (const auto& country : sortedCountries)
    {
        result.push_back(country.first + ":" + std::to_string(country.second));
    }

    if (result.empty()) {
        result.push_back("none:0");
    }

    return result;
}
