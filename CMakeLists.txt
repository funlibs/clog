cmake_minimum_required (VERSION 2.6)
project (CLOG)

include_directories (.)

# Tests
add_executable (clog_test
  clog_test.c
  clog.h)

enable_testing()
add_test (NAME Main          COMMAND clog_test)

