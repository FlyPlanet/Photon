cmake_minimum_required(VERSION 3.0)
PROJECT(PhotonDemo VERSION 0.1)
add_subdirectory(Photon)
set(CMAKE_CXX_STANDARD 20)
find_package(glad)
add_executable(${PROJECT_NAME} demo/HelloWindow.cpp)


target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Photon
        glad::glad
        )
