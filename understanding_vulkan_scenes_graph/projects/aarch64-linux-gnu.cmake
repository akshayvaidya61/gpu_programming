# Toolchain file for aarch64-none-linux-gnu
cmake_minimum_required(VERSION 3.10)

# Set the target platform and architecture
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PATH_TO_TIOVX "/home/akshay/ti/ti-processor-sdk-rtos-j721s2-evm-09_02_00_05")
set(CMAKE_C_COMPILER "/home/akshay/ti/arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/home/akshay/ti/arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++")
set(PKG_CONFIG_EXECUTABLE "/usr/bin/pkg-config")

# Set the sysroot and search paths
set(CMAKE_SYSROOT "${PATH_TO_TIOVX}/targetfs")
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH ${CMAKE_SYSROOT})
set(CMAKE_FIND_ROOT_PATH_LIBRARY ${CMAKE_SYSROOT})


# Set compiler flags
set(CMAKE_CXX_FLAGS "-Wall -g -O0")
set(CMAKE_C_FLAGS "-Wall -g -O0")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections,--print-memory-usage,-L${PATH_TO_TIOVX}/targetfs/usr/lib")
add_compile_options(-DSOC_J721S2)
