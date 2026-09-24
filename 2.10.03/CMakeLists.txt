# CMakeList.txt: проект CMake для 2.10.03; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2.10.03")

# подлкючаем библиотеки
add_library(2.10.02_dynamic_lib SHARED "../2.10.02_dynamic_lib/Leaver.h"
	"../2.10.02_dynamic_lib/Leaver.cpp")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (2.10.03 "2.10.03.cpp" )

# линкуем либу
target_link_libraries(2.10.03 PRIVATE 2.10.02_dynamic_lib)

# подключаем директорию
target_include_directories(2.10.03 PRIVATE "../2.10.02_dynamic_lib")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2.10.03 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
