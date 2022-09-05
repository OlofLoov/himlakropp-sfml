add_library(assets "")

target_sources(assets
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/AssetsManager.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/AssetsManager.hpp
  )
target_include_directories(assets
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )