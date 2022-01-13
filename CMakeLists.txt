cmake_minimum_required(VERSION 3.3.1)
project(Test)


set(OpenCV_DIR "C:/Studia/Semestr V/Projekt_kompetencyjny/OpenCV-MinGW-Build-OpenCV-4.5.2-x64/x64/mingw/lib")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

add_executable(Test main.cpp src/ColorHsv.h src/constants.h src/Enemy.h src/Game.h src/MyPoint.h src/Obstacle.h src/Player.h src/Visualisation.h)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("C:/Studia/Semestr V/Projekt_kompetencyjny/SFML-2.5.1/include")

find_package(OpenCV 4.5.2 REQUIRED)
find_package(SFML 2.5 REQUIRED system window graphics)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(Test ${OpenCV_LIBS} ${SFML_LIBRARIES})

file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})

