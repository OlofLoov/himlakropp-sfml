add_library(scenes "")

target_sources(scenes
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/SolarSystemScene.cpp
    ${CMAKE_CURRENT_LIST_DIR}/MenuScene.cpp

  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/SolarSystemScene.hpp
    ${CMAKE_CURRENT_LIST_DIR}/MenuScene.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Scenes.hpp
  )
target_include_directories(scenes
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

  target_link_libraries(scenes
    PRIVATE    
    assets
    celestial
    game
  )