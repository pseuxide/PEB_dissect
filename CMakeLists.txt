# CMakeList.txt : CMake project for PEB_dissect, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PEB_dissect")

# Add source to this project's executable.
add_executable (PEB_dissect "PEB_dissect.cpp" "PEB_dissect.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PEB_dissect PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
