cmake_minimum_required(VERSION 3.14)

project(Peds
  VERSION 0.1
  DESCRIPTION "Programmable 3D Sight"
  LANGUAGES CXX)

if(MSVC)
  add_compile_options(/W3 /WX)
else()
  add_compile_options(-W -Wall -Werror -Wpedantic)
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
