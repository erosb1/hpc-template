# HPC C++23 Benchmarking Template

A lightweight template for prototyping and microbenchmarking high-performance algorithms in C++23 using Google Benchmark.

## Intended Use
This repository serves as a starter kit to quickly set up isolated benchmarking environments.
It is primarily intended for linear algebra workloads, but works for benchmarking any algorithm.

---

## Toolchain & Stack
This template targets development on linux/macos and relies on the following infrastructure:

* **Build System:** [CMake](https://cmake.org/) and [Ninja](https://ninja-build.org/).
* **Package Management:** [vcpkg](https://vcpkg.io/) running in manifest mode.

### Core Packages Included
* **Google Benchmark:** Microbenchmarking framework featuring multithreading, and statistical warmup loops.
* **Eigen3:** A high-performance C++ library for linear algebra.

---

## Prerequisites

Before configuring the project, ensure your host system has the necessary build tools and that your `vcpkg` root environment variable is exposed.

### 1. Install System Tools
* **Linux (Debian/Ubuntu):**
    ```bash
    sudo apt update && sudo apt install build-essential ninja-build
    ```
* **macOS (via Homebrew):**
    ```bash
    brew install cmake ninja
    ```

### 2. Set Environment Variable
Ensure the path to the global `vcpkg` repository clone is exported in your shell:
```bash
export VCPKG_ROOT="$HOME/vcpkg"
```

---

## Build Instructions
This repository uses the following two CMake presets:

### 1. Debug Build
Compiles with `-g` and no optimizations. Use this one for development.
```bash
cmake --preset debug

cmake --build build/debug

./build/debug/bench_runner
```

### 2. Release Build
Compiles with `-O3` and `-march=native`. Use this one for benchmarking.
```bash
cmake --preset release-native

cmake --build build/release-native

./build/release-native/bench_runner
``` 

