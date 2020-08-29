
add_executable(server server.cpp )
add_executable(client client.cpp )

target_link_libraries(server ${CPPCONLIB})
target_link_libraries(client ${CPPCONLIB})