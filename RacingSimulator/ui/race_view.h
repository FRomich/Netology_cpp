#pragma once
#include <string>
#include <vector>

struct RaceView
{
    std::string raceType;
    int distance{};
    std::vector<std::string> vehicles;
    std::string stage;
    std::string message;
    std::string result;
};