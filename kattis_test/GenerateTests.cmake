file(GLOB problem_files
    RELATIVE ${kattis_SOURCE_DIR}/kattis/src/
    ${kattis_SOURCE_DIR}/kattis/src/kattis/problems/[^_]*.hpp)

foreach(problem ${problem_files})
    get_filename_component(problem_name ${problem} NAME_WE)
    configure_file ("src/test_template.hpp.in" "src/tests/${problem_name}.cpp")
endforeach()