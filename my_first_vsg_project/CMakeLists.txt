cmake_minimum_required(VERSION 3.10)

# Set the project name
project(HelloWorld CXX)

set(PATH_TO_TIOVX /home/akshay/ti/ti-processor-sdk-rtos-j721s2-evm-09_02_00_05)

# Set the cross-compiler
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_CXX_FLAGS "-Wall -g -O0")
set(CMAKE_C_FLAGS "-Wall -g -O0")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections,--print-memory-usage,-L${PATH_TO_TIOVX}/targetfs/usr/lib")
add_compile_options(-DSOC_J721S2)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# targetfs
set(CMAKE_FIND_ROOT_PATH ${PATH_TO_TIOVX}/targetfs)
# Ensure the toolchain uses the sysroot
set(CMAKE_SYSROOT ${PATH_TO_TIOVX}/targetfs)
set(CMAKE_FIND_ROOT_PATH ${CMAKE_SYSROOT})

# Set the search modes
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Specify the cross compiler and tools
set(CMAKE_C_COMPILER /home/akshay/ti/arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /home/akshay/ti/arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

file(GLOB SOURCES "./*.cpp")

# Define the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE
        ${PATH_TO_TIOVX}/targetfs/usr/include/processor_sdk/tiovx/include
        ${PATH_TO_TIOVX}/targetfs/usr/include/processor_sdk/tiovx/kernels/include
        ${PATH_TO_TIOVX}/targetfs/usr/include/processor_sdk/tiovx/utils/include
        ${PATH_TO_TIOVX}/targetfs/usr/include/opencv4
)

target_link_libraries(${PROJECT_NAME}
        -L${PATH_TO_TIOVX}/targetfs/usr/lib/
        -L${PATH_TO_TIOVX}/targetfs/usr/include/processor_sdk/tiovx/lib
        -L${PATH_TO_TIOVX}/targetfs/usr/include/processor_sdk/tiovx/kernel/lib
        -L${PATH_TO_TIOVX}/tiovx/lib/J721S2/A72/LINUX/release
        -L${PATH_TO_TIOVX}/app_utils/lib/J721S2/A72/LINUX/release
        -L${PATH_TO_TIOVX}/targetfs/usr/lib
        -L${PATH_TO_TIOVX}/vision_apps/out/J721S2/A72/LINUX/release
        -lvsg
        -lvulkan
)
