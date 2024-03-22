# CMakeList.txt : CMake project for Assigment1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Assigment1 "Game.cpp" "Game.h" "game_title.h" "util.cpp" "util.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Assigment1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
