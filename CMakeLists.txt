
cmake_minimum_required(VERSION 3.1)


set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 " )


project(FPV_OpenCV)


find_package(OpenCV REQUIRED)



add_executable(re re.cpp)
add_executable(se se.cpp)


target_link_libraries(re PRIVATE ${OpenCV_LIBS})
target_link_libraries(se PRIVATE ${OpenCV_LIBS})
