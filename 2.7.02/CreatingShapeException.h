#pragma once

#include <stdexcept>

class CreatingShapeException : public std::domain_error
{
public:
	CreatingShapeException(const char* message);
};
