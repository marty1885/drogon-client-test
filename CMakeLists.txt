cmake_minimum_required(VERSION 3.15)
project(drogon_client_test)

add_executable(server1)
find_package(Drogon CONFIG REQUIRED)
target_sources(server1 PRIVATE server1.cpp)
target_link_libraries(server1 PRIVATE Drogon::Drogon)


add_executable(server2)
target_sources(server2 PRIVATE server2.cpp)
target_link_libraries(server2 PRIVATE Drogon::Drogon)
