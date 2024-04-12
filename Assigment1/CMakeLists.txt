# CMakeList.txt : CMake project for Assigment1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Assigment1 "Game.cpp" "Game.h" "game_title.h" "util.cpp" "util.h" "Moons/AbstractMoon.h" "main.cpp" "Moons/AbstractMoon.cpp" "Weather/Weather.cpp" "Weather/Weather.h"        "Simulator.cpp"   "Moons/Corporation.h" "Moons/Corporation.cpp" "Moons/MoonManager.cpp" "Moons/MoonManager.h" "Moons/Prototyping.h" "Moons/Prototyping.cpp" "Moons/Insurance.h" "Moons/Pledge.h" "Moons/Defense.h" "Moons/Insurance.cpp" "Moons/Pledge.cpp" "Moons/Defense.cpp" "Items/ItemManager.h" "Items/ItemManager.cpp" "Items/AbstractItem.h" "Items/AbstractItem.cpp" "Items/Flashlight.h" "Items/Flashlight.cpp" "Items/Shovel.h" "Items/Shovel.cpp" "Items/ProFlashlight.h" "Items/ProFlashlight.cpp" "Items/Teleporter.h" "Items/Teleporter.cpp" "Items/InverseTeleporter.h" "Items/InverseTeleporter.cpp" "Items/Backpack.h" "Items/Backpack.cpp" "Items/HydraulicsMk2.h" "Items/HydraulicsMk2.cpp" "Simulator.h" "Moons/April.h" "Moons/Tore.h" "Moons/Hyperion.h" "Moons/April.cpp" "Moons/Tore.cpp" "Moons/Hyperion.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Assigment1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
