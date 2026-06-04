cmake_minimum_required(VERSION 3.23)
project(HPC_Benchmark_Suite LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Eigen3 REQUIRED)
find_package(benchmark REQUIRED)

add_executable(bench_runner src/main.cpp)

if(MSVC)
    # Windows
    target_compile_options(bench_runner PRIVATE $<$<CONFIG:Release>:/O2 /arch:AVX2>)
elseif(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    # Apple Silicon Mac (ARM64)
    target_compile_options(bench_runner PRIVATE $<$<CONFIG:Release>:-O3>)
else()
    # Linux or Intel Mac (x86_64)
    target_compile_options(bench_runner PRIVATE -march=native)
    target_compile_options(bench_runner PRIVATE $<$<CONFIG:Release>:-O3>)
endif()

target_link_libraries(bench_runner PRIVATE 
    Eigen3::Eigen
    benchmark::benchmark_main
)
