# -----------------------------------------------------------------------------
# Get google test suite

include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY  https://github.com/google/googletest.git
  GIT_TAG         release-1.10.0)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# -----------------------------------------------------------------------------
# Setup my tests

include(GoogleTest) # for gtest_discover_tests
add_executable(TestP3DS testlib.cpp)
target_link_libraries(TestP3DS
  PRIVATE
    gtest gtest_main
    Peds::Peds) 
gtest_discover_tests(TestP3DS)
