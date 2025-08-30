cmake_minimum_required(VERSION 3.15)
project(AppwriteSDK VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform-specific configurations
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-DNOMINMAX)
endif()

# Include Conan toolchain
include(${CMAKE_BINARY_DIR}/Release/generators/conan_toolchain.cmake)

# Make PkgConfig optional for Windows compatibility
find_package(PkgConfig QUIET)

# CRITICAL: Use Conan targets directly without find_package
# This bypasses CMake's problematic built-in find modules
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/generators ${CMAKE_PREFIX_PATH})

# Include Conan's generated target files directly
include(${CMAKE_BINARY_DIR}/generators/CURL-config.cmake OPTIONAL)
include(${CMAKE_BINARY_DIR}/generators/nlohmann_json-config.cmake OPTIONAL)

# Alternative: Load all Conan targets
file(GLOB CONAN_CONFIGS "${CMAKE_BINARY_DIR}/generators/*-config.cmake")
foreach(config_file ${CONAN_CONFIGS})
    include(${config_file})
endforeach()

# Create a simple library (adjust source file locations as needed)
# For testing, create a minimal library
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dummy.cpp
)

# If dummy.cpp doesn't exist, create a header-only library
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/dummy.cpp)
    add_library(AppwriteSDK INTERFACE)
    target_include_directories(AppwriteSDK 
        INTERFACE 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
    )
else()
    add_library(AppwriteSDK ${SOURCES})
    target_include_directories(AppwriteSDK 
        PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
endif()

# Link libraries using Conan targets (these should be available now)
# Handle CURL target compatibility
if(TARGET CURL::libcurl)
    set(CURL_TARGET CURL::libcurl)
elseif(TARGET CURL::CURL)
    set(CURL_TARGET CURL::CURL)
else()
    # Fallback to variables
    set(CURL_TARGET ${CURL_LIBRARIES})
endif()

target_link_libraries(AppwriteSDK 
    INTERFACE 
        ${CURL_TARGET}
        nlohmann_json::nlohmann_json
)

if(WIN32)
    target_link_libraries(AppwriteSDK INTERFACE ws2_32 wldap32 crypt32)
endif()

message(STATUS "AppwriteSDK configured successfully with CURL target: ${CURL_TARGET}")

# Windows-specific linking
if(WIN32)
    target_link_libraries(AppwriteSDK PRIVATE ws2_32 wldap32 crypt32)
endif()

# Print debug info
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
message(STATUS "Available targets: ${CMAKE_BINARY_DIR}/generators")
