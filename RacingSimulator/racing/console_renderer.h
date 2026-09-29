#pragma once
#include "race.h"
#include "vehicle.h"

namespace my_racing {
	class RACINGLIBRARY ConsoleRenderer
	{
	public:
		static void clear();
		static void draw(const Race& race);
	};
}
