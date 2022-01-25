cmake_minimum_required(VERSION 3.0.0)
project(Photon VERSION 0.0.1)

set(DCMAKE_TOOLCHAIN_FILE /opt/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(glfw3 CONFIG REQUIRED)

FILE (GLOB ALL_SOURCES "*.cpp" "*.c" "./core/*.cpp" "./core/*.c" )
FILE (GLOB ALL_INCLUDES "*.hpp" "*.h" "./core/*.hpp"  "./core/*.h" )


SET (ALL_SRCS 
	 ${ALL_SOURCES}
	 ${ALL_INCLUDES}
)
message(以下文件将会被编译)
foreach(file ${ALL_SRCS})
    message(${file})
endforeach(file ${ALL_SRCS})

add_library(${PROJECT_NAME} STATIC ${ALL_SRCS})
target_precompile_headers(${PROJECT_NAME} PUBLIC pch.h)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw ${CMAKE_DL_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})