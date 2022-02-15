cmake_minimum_required(VERSION 3.0)
PROJECT(PhotonDemo VERSION 0.1)
add_subdirectory(Photon)
set(CMAKE_CXX_STANDARD 20)
find_package(glad)
add_executable(${PROJECT_NAME} demo/HelloWindow.cpp)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Photon
        glad::glad
        )
