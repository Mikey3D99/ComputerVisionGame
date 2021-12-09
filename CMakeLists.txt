cmake_minimum_required(VERSION 3.3.1)
project(Test)

#<<<<<<< Updated upstream
#set(OpenCV_DIR "C:/Studia/Semestr V/Projekt_kompetencyjny/OpenCV-MinGW-Build-OpenCV-4.5.2-x64/x64/mingw/lib")
#set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#
#add_executable(Test main.cpp ball_handler.cpp ball_handler.h src/MyPoint.cpp game.cpp game.h)
#
#include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories("C:/Studia/Semestr V/Projekt_kompetencyjny/SFML-2.5.1/include")
#
#find_package(OpenCV 4.5.2 REQUIRED)
#find_package(SFML 2.5 REQUIRED system window graphics)
#
#include_directories(${SFML_INCLUDE_DIR})
#target_link_libraries(Test ${OpenCV_LIBS} ${SFML_LIBRARIES})
#
#file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
#file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
#=======
set(OpenCV_DIR /Users/marcinswiderek/opencv/build_opencv)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ball_handler.cpp ball_handler.h src/MyPoint.cpp src/Game.cpp src/MyPoint.h src/Game.h src/Obstacle.cpp src/Obstacle.h src/constants.h src/Player.cpp src/Player.h src/enemy.h src/enemy.cpp)
add_executable(Test ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package( OpenCV REQUIRED )
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)
include_directories(${SFML_INCLUDE_DIRS})

target_link_libraries(Test
        ${OpenCV_LIBS}
        sfml-system sfml-window sfml-graphics sfml-audio sfml-network
)
#>>>>>>> Stashed changes
