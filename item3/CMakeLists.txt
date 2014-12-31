CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(item3)



INCLUDE_DIRECTORIES(
    ${/usr/local/include}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64")


ADD_EXECUTABLE(item3 item3.cpp)




