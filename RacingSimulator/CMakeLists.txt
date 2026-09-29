cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RacingSimulator")

add_subdirectory(racing)

add_executable (RacingSimulator "RacingSimulator.cpp" )

target_link_libraries(RacingSimulator PRIVATE
    Racing
)

target_include_directories(RacingSimulator PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/racing
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RacingSimulator PROPERTY CXX_STANDARD 20)
endif()

add_custom_command(TARGET RacingSimulator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Racing>
        $<TARGET_FILE_DIR:RacingSimulator>
)
