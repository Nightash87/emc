CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(item5)



INCLUDE_DIRECTORIES(
    ${/usr/local/include}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64")




ADD_EXECUTABLE(item5 item5.cpp)




