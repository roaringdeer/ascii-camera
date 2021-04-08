cmake_minimum_required(VERSION 3.0.0)
project(ascii-camera VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ascii-camera main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# == OpenCV (3.4.5.0) / (4.0.1) configuration ==
# Where to find CMake modules and OpenCV
set(OpenCV_DIR "E:\\opencv\\build")  #check path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}\\cmake\\")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Add libs you need
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)

# Linking
target_link_libraries(ascii-camera ${OpenCV_LIBS})