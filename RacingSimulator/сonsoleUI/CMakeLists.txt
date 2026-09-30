add_library(ConsoleUI SHARED
    "consoleUI_export.h"
    "consoleUI.cpp"
    "consoleUI.h"
     )

target_compile_definitions(ConsoleUI PRIVATE
    CONSOLEUILIBRARYDYNAMIC_EXPORTS
)

target_compile_features(ConsoleUI PUBLIC
    cxx_std_20
)

target_include_directories(ConsoleUI
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(ConsoleUI
    PUBLIC
        ui
)