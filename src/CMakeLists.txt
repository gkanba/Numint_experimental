cmake_minimum_required(VERSION 3.20)

project(Numint CXX)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)
add_compile_options(-Wall -Wextra -std=c++17)
add_executable(exec main.cpp ODE.cpp Integrate.cpp TimeSeries.cpp)
target_link_libraries(exec Eigen3::Eigen)
