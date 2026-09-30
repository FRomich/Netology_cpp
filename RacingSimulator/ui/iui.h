#pragma once
#include <string_view>

#include "race_view.h"

class IUI
{
public:
	virtual ~IUI() = default;

	virtual void clear() = 0;

    virtual void show(std::string_view text) = 0;

    virtual int getKey() = 0;

    virtual void getAnyKey() = 0;

    virtual int getInt() = 0;

    virtual void draw(const RaceView& view) = 0;
};
