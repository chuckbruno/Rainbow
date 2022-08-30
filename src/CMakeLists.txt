# CMakeList.txt : CMake project for Raytracing, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Raytracing   "qbImage.hpp" "qbImage.cpp" "CApp.h" "CApp.cpp" "main.cpp")

# TODO: Add tests and install targets if needed.
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(Raytracing PRIVATE SDL2::SDL2 SDL2::SDL2main)


