find_package(Doxygen REQUIRED dot OPTIONAL_COMPONENTS mscgen dia)
set(DOXYGEN_HAVE_DOT true)

# -----------------------------------------------------------------------------
# Add library documentation
file(GLOB_RECURSE LIBPEDS_FILES
  LIST_DIRECTORIES false
  CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/../lib/*.h"
  "${CMAKE_CURRENT_SOURCE_DIR}/../lib/*.cpp"
)

# Add a main page
list(APPEND LIBPEDS_FILES "${CMAKE_CURRENT_SOURCE_DIR}/MainPage.md")
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${CMAKE_CURRENT_SOURCE_DIR}/MainPage.md")

set(DOXYGEN_WARN_IF_UNDOCUMENTED "NO")
set(DOXYGEN_QUIET "YES")
set(DOXYGEN_PROJECT_NAME "P3DS Library")
set(DOXYGEN_PROJECT_BRIEF "P3DS library for easy programmable rendering using OpenGL")
doxygen_add_docs(PedsLibDoc
  ${LIBPEDS_FILES}
  ALL
  COMMENT "Building P3DS library documentation ...")

install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html/ DESTINATION ${CMAKE_INSTALL_PREFIX}/docs/html)
