file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${SysLogPreLoadRootKit_SOURCE_DIR}/include/slrk/*.h")

add_library(rootkit_library syslog.c ${HEADER_LIST})

target_include_directories(rootkit_library PUBLIC ../include)

target_compile_features(rootkit_library PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

