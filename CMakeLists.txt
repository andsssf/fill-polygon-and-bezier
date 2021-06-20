cmake_minimum_required(VERSION 3.0.0)
project(FillPolygon_And_Bezier VERSION 0.1.0)

include_directories(include)
link_directories(lib)
link_libraries("libfreeglut.a" "glew32.lib" "opengl32.lib" "glu32.lib")

aux_source_directory(src SOURCE_LIST)

add_executable(FillPolygon_And_Bezier "${SOURCE_LIST}")
