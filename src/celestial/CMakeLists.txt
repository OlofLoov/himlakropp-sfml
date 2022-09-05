add_library(celestial "")

target_sources(celestial
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/CelestialBody.cpp
    ${CMAKE_CURRENT_LIST_DIR}/CelestialBodyCreator.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/CelestialBody.hpp
    ${CMAKE_CURRENT_LIST_DIR}/CelestialBodyCreator.hpp
  )
target_include_directories(celestial
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(celestial
  PRIVATE
  assets  
)