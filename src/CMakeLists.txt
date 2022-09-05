set(CMAKE_OSX_ARCHITECTURES "x86_64")
add_executable(himlakropp Main.cpp)
include_directories(${CMAKE_CURRENT_LIST_DIR}/external/sfml/include)

add_subdirectory(celestial)
add_subdirectory(assets)
add_subdirectory(scenes)
add_subdirectory(game)

# Provide the full path to the library, so CMake knows where to find it.

target_link_libraries(himlakropp
  PRIVATE
    scenes
    game
    celestial
    assets
    
    ${CMAKE_CURRENT_LIST_DIR}/external/sfml/lib/libsfml-graphics.dylib
    ${CMAKE_CURRENT_LIST_DIR}/external/sfml/lib/libsfml-window.dylib
    ${CMAKE_CURRENT_LIST_DIR}/external/sfml/lib/libsfml-system.dylib

  )