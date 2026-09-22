# CMakeList.txt: проект CMake для 2.9.02; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2.9.02")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (2.9.02 "2.9.02.cpp" 
	"EquilateralTriangle.cpp" "EquilateralTriangle.h" 
	"IsoscelesTriangle.cpp" "IsoscelesTriangle.h" 
	"Parallelogram.cpp" "Parallelogram.h" 
	"Quad.cpp" "Quad.h" 
	"Rhombus.cpp" "Rhombus.h" 
	"RightTriangle.cpp" "RightTriangle.h" 
	"Shape.cpp" "Shape.h" 
	"Square.cpp" "Square.h" 
	"Triangle.cpp" "Triangle.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2.9.02 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
