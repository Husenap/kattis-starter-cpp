if(NOT TARGET compiler_features)
    add_library(compiler_features INTERFACE)

    # Kattis is sadly still running C++17
    target_compile_features(compiler_features INTERFACE cxx_std_17)
endif()