CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
PROJECT(emc)



INCLUDE_DIRECTORIES(
    ${/usr/local/include}
)

set(CMAKE_LEGACY_CYGWIN_WIN32 0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


add_subdirectory(item1)
add_subdirectory(item3)
add_subdirectory(item5)
add_subdirectory(item7)
add_subdirectory(item15)
add_subdirectory(item18)
add_subdirectory(item19)
add_subdirectory(item22)
add_subdirectory(item25)
add_subdirectory(item26)
add_subdirectory(item27)
add_subdirectory(item29)