cmake_minimum_required(VERSION 3.14)

project(Peds
  VERSION 0.1
  DESCRIPTION "Programmable 3D Sight"
  LANGUAGES CXX)

if(MSVC)
  add_compile_options(/W3)
else()
  add_compile_options(-W -Wall -Wpedantic -Wshadow -Wunused-variable -Wunused-parameter)
endif()

option(ENABLE_COVERAGE "Enable coverage" OFF)
mark_as_advanced(ENABLE_COVERAGE)
if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-g -O0 -fprofile-arcs -ftest-coverage)
  add_link_options(-fprofile-arcs -ftest-coverage)
endif()

# P3DS library
add_subdirectory(lib)

# P3DSight viewer
option(BUILD_P3DS_VIEWER "Build P3DSight viewer application" ON)
if (BUILD_P3DS_VIEWER)
  add_subdirectory(app)
endif()

# P3DS documentation
option(BUILD_DOCUMENTATION "Build P3DS library documentation" OFF)
if (BUILD_DOCUMENTATION)
  add_subdirectory(docs)
endif()

# P3DS testing
option(BUILD_TESTING "Build testing for P3DS library" OFF)
if (BUILD_TESTING)
  add_subdirectory(tests)
endif()
