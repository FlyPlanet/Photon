cmake_minimum_required(VERSION 3.0)
project(Photon VERSION 0.1)


FILE(GLOB SRC_LIST "./core/*.cpp" "./core/*.c")
FILE(GLOB HEADER_LIST "./core/*.hpp" "./core/*.h")

message(源文件:)
foreach(_v ${SRC_LIST})
    message(${_v})
endforeach(_v ${SRC_LIST})

message(头文件:)
foreach(_v ${HEADER_LIST})
    message(${_v})
endforeach(_v ${HEADER_LIST})

set(CMAKE_CXX_STANDARD 20)
#引用vcpkg
include(/home/skywards/Opensource/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)


add_library(${PROJECT_NAME} STATIC ${SRC_LIST} ${HEADER_LIST})
target_precompile_headers(${PROJECT_NAME} PUBLIC pch.h)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE freetype)
