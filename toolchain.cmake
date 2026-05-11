# toolchain-rpi-aarch64.cmake

# ─────────────────────────────────────────────────────────────
# Target system
# ─────────────────────────────────────────────────────────────
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# ─────────────────────────────────────────────────────────────
# Cross compiler path
# Example:
# Linux   : /opt/rpi-toolchain/bin/
# Windows : C:/rpi-toolchain/bin/
# ─────────────────────────────────────────────────────────────
set(TOOLCHAIN_PATH "/opt/rpi-toolchain/bin")

# Compiler
set(CMAKE_C_COMPILER
    ${TOOLCHAIN_PATH}/aarch64-linux-gnu-gcc)

set(CMAKE_CXX_COMPILER
    ${TOOLCHAIN_PATH}/aarch64-linux-gnu-g++)

# ─────────────────────────────────────────────────────────────
# Sysroot (Raspberry Pi root filesystem)
# ─────────────────────────────────────────────────────────────
set(CMAKE_SYSROOT "/opt/rpi-sysroot")

# Search paths
set(CMAKE_FIND_ROOT_PATH
    ${CMAKE_SYSROOT}
)

# ─────────────────────────────────────────────────────────────
# CMake search behavior
# ─────────────────────────────────────────────────────────────
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)

set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# ─────────────────────────────────────────────────────────────
# ARM64 Flags
# ─────────────────────────────────────────────────────────────
set(CMAKE_C_FLAGS
    "-march=armv8-a"
)

set(CMAKE_CXX_FLAGS
    "-march=armv8-a"
)

# ─────────────────────────────────────────────────────────────
# Optional optimizations
# ─────────────────────────────────────────────────────────────
set(CMAKE_CXX_FLAGS_RELEASE
    "-O2"
)

set(CMAKE_CXX_FLAGS_DEBUG
    "-g -O0"
)

# ─────────────────────────────────────────────────────────────
# Threads
# ─────────────────────────────────────────────────────────────
set(THREADS_PREFER_PTHREAD_FLAG ON)