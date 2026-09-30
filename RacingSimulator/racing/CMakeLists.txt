add_library(Racing SHARED
    "racing_export.h"
    "vehicle.cpp" "vehicle.h"
    "ground_vehicles.h" "ground_vehicles.cpp" 
    "air_vehicles.h" "air_vehicles.cpp"
    "camel.cpp" "camel.h"
    "fast_camel.h" "fast_camel.cpp" 
    "centaur.h" "centaur.cpp" 
    "all_terrain_boots.h" "all_terrain_boots.cpp" 
    "carpet_plane.h" "carpet_plane.cpp" 
    "eagle.h" "eagle.cpp"
    "broom.h" "broom.cpp"
    "race.h" "race.cpp"
    "console_renderer.h" "console_renderer.cpp" )

target_compile_definitions(Racing PRIVATE
    RACINGLIBRARYDYNAMIC_EXPORTS
)

target_compile_features(Racing PUBLIC
    cxx_std_20
)
