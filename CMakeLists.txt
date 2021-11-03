cmake_minimum_required(VERSION 3.3.1)

project(Test)

set(OpenCV_DIR "C:/Studia/Semestr V/Projekt_kompetencyjny/OpenCV-MinGW-Build-OpenCV-4.5.2-x64/x64/mingw/lib")

find_package(OpenCV 4.5.2 REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
)

add_executable(Test
        main.cpp
        # You can put here your .h and .cpp files to expand the example.
        )

target_link_libraries(Test
        ${OpenCV_LIBS}
        )
