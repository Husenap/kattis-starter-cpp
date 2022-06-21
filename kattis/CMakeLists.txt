set(target_name "kattis")

file(GLOB src_problems ${CMAKE_CURRENT_SOURCE_DIR}/src/kattis/problems/[^_]*.hpp)

set(src_shared
    "src/kattis/shared/shared_constants.hpp"
    "src/kattis/shared/shared_string.hpp"
    "src/kattis/shared/shared_types.hpp")

set(src_files
    "src/dummy.cpp"
    ${src_problems}
    ${src_shared})

# Project
add_library(${target_name} STATIC ${src_files})
set_target_properties(${target_name} PROPERTIES LINKER_LANGUAGE CXX)
set_source_files_properties(${src_problems} PROPERTIES HEADER_FILE_ONLY TRUE)

target_link_libraries(${target_name}
    compiler_features
    compiler_warnings)

target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/kattis/shared)

source_group("src/problems" FILES ${src_problems})
source_group("src/shared" FILES ${src_shared})

set_target_properties(${target_name} PROPERTIES FOLDER ${${PROJECT_NAME}_FOLDER})