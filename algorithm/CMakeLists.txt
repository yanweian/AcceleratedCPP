cmake_minimum_required(VERSION 3.0.0)
project(algorithm VERSION 0.1.0)

include(CTest)
enable_testing()
add_subdirectory(test)

aux_source_directory(./ Dir_SRCs)
add_executable(algorithm ${Dir_SRCs})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
