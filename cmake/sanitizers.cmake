function(enable_sanitizers target_name)

  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)
    if(ENABLE_COVERAGE)
      target_compile_options(${target_name} INTERFACE --coverage -O0 -g)
      target_link_libraries(${target_name} INTERFACE --coverage)
    endif()
  endif()

endfunction()