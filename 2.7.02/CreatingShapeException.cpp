#include "CreatingShapeException.h"

CreatingShapeException::CreatingShapeException(const char* message)
	: std::domain_error(message){};


