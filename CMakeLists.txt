cmake_minimum_required(VERSION 3.20)

project(pomodoro-cli)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src
)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

file (
  GLOB_RECURSE

  SOURCES

  **.cpp
)

add_executable(pomodoro-cli ${SOURCES})

