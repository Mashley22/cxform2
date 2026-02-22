cmake_minimum_required(VERSION 3.14)

project(cxform
  VERSION 0.71
  LANGUAGES C
)

add_library(cxform
  src/cxform-auto.c
  src/cxform-manual.c
)

target_include_directories(cxform 
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

if(UNIX)
  target_link_libraries(cxform PRIVATE m)
endif()

add_executable(cx
  src/main.c
)

target_link_libraries(cx
  PUBLIC
    cxform
)
