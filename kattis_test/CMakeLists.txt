set(target_name "kattis_test")

include("GenerateTests.cmake")

file(GLOB_RECURSE src_problems ${CMAKE_CURRENT_BINARY_DIR}/src/tests/*)

set(src_shared
    "src/shared/shared_string.cpp")

set(src_files
    "src/precompiled.hpp"
    "src/test_runner.cpp"
    "src/test_runner.hpp"
    ${src_shared}
    ${src_problems})

add_executable(${target_name} ${src_files})

target_link_libraries(${target_name}
    kattis
    gmock_main)

target_precompile_headers(${target_name} PRIVATE "src/precompiled.hpp")

set_target_properties(${target_name} PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER}/test)

gtest_discover_tests(${target_name}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/input/)

source_group("src/problems" FILES ${src_problems})
source_group("src/shared" FILES ${src_shared})

add_custom_command(
    TARGET ${target_name} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/input/
    $<TARGET_FILE_DIR:${target_name}>/)
