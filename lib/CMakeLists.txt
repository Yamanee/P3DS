# -----------------------------------------------------------------------------
# Variables
set(LIB_NAME Peds)            # Target library name
set(SOURCES                   # Implementation
  src/Maths/Details.cpp
  src/Maths/Details.h
  src/Maths/Vector.cpp
)
set(HEADERS                   # Public API
  include/Maths/Vector.h)

# -----------------------------------------------------------------------------
# Configure environment
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

if(NOT APPLE)
  set(CMAKE_INSTALL_RPATH $ORIGIN)
endif()

# -----------------------------------------------------------------------------
# Declare the target library and configure it
add_library(${LIB_NAME} SHARED ${SOURCES} ${HEADERS})
add_library(${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

include(GenerateExportHeader)
generate_export_header(${LIB_NAME} EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/peds_export.h)
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/Configuration.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/include/Configuration.h")

target_include_directories(${LIB_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
  PRIVATE
    src)

set_target_properties(${LIB_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  CXX_EXTENSIONS OFF)
target_compile_features(${LIB_NAME} PUBLIC cxx_std_17)

include(CheckIPOSupported)
check_ipo_supported(RESULT isIPOSupported)
if(isIPOSupported)
  message(STATUS "libPeds : interprocedural optimization linking enabled")
  set_target_properties(${LIB_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

# -----------------------------------------------------------------------------
# Install target
include(GNUInstallDirs)
install(TARGETS ${LIB_NAME}
    EXPORT "${LIB_NAME}Config"
    ARCHIVE   DESTINATION ${CMAKE_INSTALL_LIBDIR}
              COMPONENT   ${LIB_NAME}_Development
    LIBRARY   DESTINATION         ${CMAKE_INSTALL_LIBDIR}
              COMPONENT           ${LIB_NAME}_Runtime
              NAMELINK_COMPONENT  ${LIB_NAME}_Development
    RUNTIME   DESTINATION ${CMAKE_INSTALL_BINDIR}
              COMPONENT   ${LIB_NAME}_Runtime)

# Install public headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIB_NAME})
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIB_NAME})

# Install Cmake configuration
install(EXPORT "${LIB_NAME}Config" DESTINATION "share/${LIB_NAME}/cmake")
export(TARGETS "${LIB_NAME}" FILE "${LIB_NAME}ConfigVersion.cmake")

# -----------------------------------------------------------------------------
# Clear variables
set(LIB_NAME)
set(SOURCES)
set(HEADERS)
