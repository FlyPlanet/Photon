cmake_minimum_required(VERSION 3.0)
PROJECT(PhotonDemo VERSION 0.1)
add_subdirectory(Photon)
add_executable(${PROJECT_NAME} demo/HelloWindow.cpp)
find_package(glad)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Photon
        glad::glad
)
