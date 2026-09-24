# CMakeList.txt: проект CMake для 2.10.05; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2.10.05")

# собираем библиотеку
add_library(2.10.04_Shape_dynemiclib SHARED 
	"../2.10.04_Shape_dynemiclib/EquilateralTriangle.cpp"
	"../2.10.04_Shape_dynemiclib/EquilateralTriangle.h"
	"../2.10.04_Shape_dynemiclib/IsoscelesTriangle.cpp"
	"../2.10.04_Shape_dynemiclib/IsoscelesTriangle.h"
	"../2.10.04_Shape_dynemiclib/Parallelogram.cpp"
	"../2.10.04_Shape_dynemiclib/Parallelogram.h"
	"../2.10.04_Shape_dynemiclib/Quad.cpp"
	"../2.10.04_Shape_dynemiclib/Quad.h"
	"../2.10.04_Shape_dynemiclib/Rhombus.cpp"
	"../2.10.04_Shape_dynemiclib/Rhombus.h"
	"../2.10.04_Shape_dynemiclib/RightTriangle.cpp"
	"../2.10.04_Shape_dynemiclib/RightTriangle.h"
	"../2.10.04_Shape_dynemiclib/Shape.cpp"
	"../2.10.04_Shape_dynemiclib/Shape.h"
	"../2.10.04_Shape_dynemiclib/Square.cpp"
	"../2.10.04_Shape_dynemiclib/Square.h"
	"../2.10.04_Shape_dynemiclib/Triangle.cpp"
	"../2.10.04_Shape_dynemiclib/Triangle.h"
)

# Устанавливаем SHAPELIBRARYDYNAMIC_EXPORTS
target_compile_definitions(2.10.04_Shape_dynemiclib PRIVATE
    SHAPELIBRARYDYNAMIC_EXPORTS
)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (2.10.05 "2.10.05.cpp" )

# линкуем либу
target_link_libraries(2.10.05 PRIVATE 2.10.04_Shape_dynemiclib)

# подключаем директорию
target_include_directories(2.10.05 PRIVATE "../2.10.04_Shape_dynemiclib")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2.10.05 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
