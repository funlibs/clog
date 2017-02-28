cmake_minimum_required (VERSION 2.6)
project (CLOG)

set (CLOG_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "clog includes")
include_directories (${CLOG_INCLUDES})

# Tests
add_executable (clog_test
  clog_test.c
  clog.h)

enable_testing()
add_test (NAME Main          COMMAND clog_test)
