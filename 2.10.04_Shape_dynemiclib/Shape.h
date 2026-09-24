#pragma once

#include <string>

#ifdef SHAPELIBRARYDYNAMIC_EXPORTS
#define SHAPELIBRARY_API __declspec(dllexport)
#else
#define SHAPELIBRARY_API __declspec(dllimport)
#endif

namespace my_shape
{
	class SHAPELIBRARY_API Shape
	{
	private:
		std::string name;

	protected:
		Shape(std::string name);

	public:
		virtual ~Shape() = default;

		std::string getName() const;
		virtual void printInfo() const = 0;
	};	
}



