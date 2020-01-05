cmake_minimum_required(VERSION 3.9)

project(mcedit_backend VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

find_library(CURSES_PANEL_LIBRARY NAMES panel DOC "The curses panel library")
if (NOT CURSES_PANEL_LIBRARY)
    message(FATAL_ERROR "Curses'panel library not found.")
endif()

add_library(MceditBackend STATIC
    src/MceditBackend
)

target_include_directories(MceditBackend PUBLIC include common-interface)
target_include_directories(MceditBackend PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(MceditBackend ${CURSES_LIBRARIES} ${CURSES_PANEL_LIBRARY})

add_executable(test
    tests/main
)

set_target_properties(test PROPERTIES EXCLUDE_FROM_ALL TRUE)
target_include_directories(test PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(test MceditBackend ${CURSES_LIBRARIES} ${CURSES_PANEL_LIBRARY})
