cmake_minimum_required(VERSION 3.6.0)
project(opengl-shadow-test VERSION 0.0.0 LANGUAGES CXX)

file(GLOB source
    "main.cpp"
    "src/*.cpp"
)

set(include_dirs 
    "include/"
)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME} ${source})
include_directories(${include_dirs})
target_link_libraries(${PROJECT_NAME} OpenGL::OpenGL GLUT::GLUT GLEW::GLEW)