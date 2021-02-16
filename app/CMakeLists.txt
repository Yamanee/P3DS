# -----------------------------------------------------------------------------
# Variables
set(PROGRAM_NAME PedSight)
set(SOURCES
  main.cpp
)

# -----------------------------------------------------------------------------
# Configure environment
find_package(Qt6 COMPONENTS Gui REQUIRED)

# -----------------------------------------------------------------------------
# Declare target executable and configure it
add_executable(${PROGRAM_NAME} ${SOURCES})

target_include_directories(${PROGRAM_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

target_link_libraries(${PROGRAM_NAME}
  PUBLIC
    Qt6::Gui
    Peds::Peds)

set_target_properties(${PROGRAM_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  CXX_EXTENSIONS OFF)
target_compile_features(${PROGRAM_NAME} PUBLIC cxx_std_17)

include(CheckIPOSupported)
check_ipo_supported(RESULT isIPOSupported)
if(isIPOSupported)
  message(STATUS "PedSight : interprocedural optimization linking enabled")
  set_target_properties(${PROGRAM_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

# -----------------------------------------------------------------------------
# Install target
include(GNUInstallDirs)
install(TARGETS ${PROGRAM_NAME}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
          COMPONENT   ${PROGRAM_NAME}_Development
  LIBRARY DESTINATION         ${CMAKE_INSTALL_LIBDIR}
          COMPONENT           ${PROGRAM_NAME}_Runtime
          NAMELINK_COMPONENT  ${PROGRAM_NAME}_Development
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
          COMPONENT   ${PROGRAM_NAME}_Runtime)
