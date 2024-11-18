cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_MODULE_PATH              "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_EXPORT_COMPILE_COMMANDS  ON)
include_directories(contrib/catch)

include(cmake/BuildFlags.cmake)
include(cmake/TestSolution.cmake)

find_package(Catch REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
        main.cpp
        BMP.cpp
        Image.cpp
        Color.cpp
        Negative.cpp
        Grayscale.cpp
        FilterFactory.cpp
        Sharpening.cpp
        EdgeDetection.cpp
        GaussianBlur.cpp
        Crop.cpp
        MatrixFilter.cpp
        Custom.cpp)

add_catch(test_io test_io.cpp BMP.cpp)
add_catch(test_color test_color.cpp Color.cpp)
add_catch(test_image test_image.cpp Image.cpp)
add_catch(test_crop test_crop.cpp Crop.cpp BMP.cpp)
add_catch(test_negative test_negative.cpp Negative.cpp BMP.cpp)
add_catch(test_grayscale test_grayscale.cpp Grayscale.cpp BMP.cpp)
add_catch(test_sharpening test_sharpening.cpp Sharpening.cpp MatrixFilter.cpp BMP.cpp)
add_catch(test_edge_detection test_edge_detection.cpp EdgeDetection.cpp Grayscale.cpp MatrixFilter.cpp BMP.cpp)
