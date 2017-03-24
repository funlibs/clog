cmake_minimum_required (VERSION 2.6)
project (CLOG)

set (CLOG_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "clog includes")
include_directories (${CLOG_INCLUDES})

add_library(clog
    clog.h
    clog.c)

# Tests
add_executable (clog_test
  clog_test.c
  clog.h)

target_link_libraries(clog_test clog)

enable_testing()
add_test (NAME Main          COMMAND clog_test)
