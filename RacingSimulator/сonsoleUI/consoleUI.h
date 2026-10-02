#pragma once

#include "consoleUI_export.h"
#include "iui.h"

namespace my_consol
{
    class CONSOLEUILIBRARY ConsoleUI : public IUI
    {
    public:
        ConsoleUI();

        void clear() override;

        void show(std::string_view text) override;

        int getKey() override;

        void getAnyKey() override;

        int getInt() override;

        void draw(const RaceView& view) override;
    };
}