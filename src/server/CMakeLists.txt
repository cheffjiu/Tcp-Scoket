add_executable(server server_main.cpp)

set_target_properties(server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin)

target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/include)