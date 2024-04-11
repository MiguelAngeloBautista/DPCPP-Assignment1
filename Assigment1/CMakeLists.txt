# CMakeList.txt : CMake project for Assigment1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Assigment1 "Game.cpp" "Game.h" "game_title.h" "util.cpp" "util.h" "Moons/AbstractMoon.h" "main.cpp" "Moons/AbstractMoon.cpp" "Weather/Weather.cpp" "Weather/Weather.h" "Weather/Clear.h" "Weather/Flooded.h" "Weather/Flooded.cpp" "Weather/Stormy.cpp" "Weather/Stormy.h" "Weather/Eclipsed.cpp" "Weather/Eclipsed.h" "Simulator.cpp"   "Moons/Corporation.h" "Moons/Corporation.cpp" "Moons/MoonManager.cpp" "Moons/MoonManager.h" "Moons/Prototyping.h" "Moons/Prototyping.cpp" "Moons/Insurance.h" "Moons/Pledge.h" "Moons/Defense.h" "Moons/Insurance.cpp" "Moons/Pledge.cpp" "Moons/Defense.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Assigment1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
