cmake_minimum_required(VERSION 3.31)
project(C__SoftwareRender)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(SDL2 REQUIRED)

add_executable(C__SoftwareRender main.cpp
        Screen.cpp
        Screen.h)
#add_executable(Learning_to_draw main.cpp Particle.cpp)

if(TARGET SDL2::SDL2)
    target_link_libraries(C__SoftwareRender PRIVATE SDL2::SDL2)
else()
    target_include_directories(C__SoftwareRender PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(C__SoftwareRender PRIVATE ${SDL2_LIBRARIES})
endif()