add_executable(client client_main.cpp)

set_target_properties(client PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/bin)

target_include_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/include)    