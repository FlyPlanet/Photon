cmake_minimum_required(VERSION 3.0)
project(Photon VERSION 0.1)

set(FILE_DIR "./core" "./extension" "./implementation/opengl")
foreach (_v ${FILE_DIR})
    FILE(GLOB SRC_LIST_F "${_v}/*.cpp" "${_v}/*.c")
    FILE(GLOB HEADER_LIST_F "${_v}/*.hpp" "${_v}/*.h" )
    set(SRC_LIST ${SRC_LIST} ${SRC_LIST_F})
    set(HEADER_LIST ${HEADER_LIST} ${HEADER_LIST_F})
endforeach ()
message(源文件:)
foreach (_v ${SRC_LIST})
    message(${_v})
endforeach (_v ${SRC_LIST})

message(头文件:)
foreach (_v ${HEADER_LIST})
    message(${_v})
endforeach (_v ${HEADER_LIST})

set(CMAKE_CXX_STANDARD 20)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
#引用vcpkg
include(/home/skywards/Opensource/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(freetype CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)
find_package(lua CONFIG REQUIRED)


add_library(${PROJECT_NAME} STATIC ${HEADER_LIST} ${SRC_LIST} Photon.h)
target_precompile_headers(${PROJECT_NAME} PUBLIC pch.h)
target_include_directories(${PROJECT_NAME} PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE freetype)
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${LUA_LIBRARIES})




