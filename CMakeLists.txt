cmake_minimum_required(VERSION 3.0.0)
project(demo VERSION 0.1.0)


AUX_SOURCE_DIRECTORY(./demo SRC_LIST) #将./下的所有*.cpp加入到SRC_LIST中
add_subdirectory(./Photon)
add_executable(${PROJECT_NAME} ${SRC_LIST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

