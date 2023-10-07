FetchContent_Declare(
  check
  GIT_REPOSITORY https://github.com/libcheck/check.git
  GIT_TAG 0.15.2
)
FetchContent_MakeAvailable(check)

add_executable(check_syslog check_syslog.c)

target_compile_features(check_syslog PRIVATE cxx_std_17)

target_link_libraries(check_syslog PRIVATE rootkit_library Check::check)

add_test(NAME check_syslogtest COMMAND check_syslog) # Command can be a target

