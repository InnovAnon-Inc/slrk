cmake_minimum_required(VERSION 3.14...3.26)

project(
  SysLogPreloadRootKit
  DESCRIPTION "Syslog PRELOAD RootKit"
  LANGUAGES C CXX)
set(CPACK_PACKAGE_NAME "SysLogPreloadRootKit")

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  include(CTest)
  find_package(Doxygen
    REQUIRED dot
    OPTIONAL_COMPONENTS mscgen dia)
  if(Doxygen_FOUND)
    add_subdirectory(docs)
  else()
    message(STATUS "Doxygen not found, not building docs")
  endif()
endif()

include(FetchContent)

add_subdirectory(src)
#add_subdirectory(apps)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
   AND BUILD_TESTING)
  add_subdirectory(tests)
endif()

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_GENERATOR "7Z;STGZ;TBZ2;TGZ;TXZ;TZ;ZIP;DEB")
set(CPACK_PACKAGE_CONTACT "InnovAnon-Inc@gmx.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Innovations Anonymous")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_COMPONENTS_GROUPING ONE_PER_GROUP)
set(CPACK_DEB_COMPONENT_INSTALL YES)
set(CPACK_SOURCE_IGNORE_FILES
  \\.git/
  build/
  ".*~$"
)
set(CPACK_VERBATIM_VARIABLES YES)

set(CPACK_PACKAGE_VENDOR "InnovAnon, Inc.")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://InnovAnon-Inc.github.io/slrk")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_STRIP_FILES TRUE)

include(CPack)

