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

if(NOT CONAN_TOOLCHAIN_FOUND)
    message(WARNING "Conan toolchain not found, proceeding without it")
endif()

# Make PkgConfig optional for Windows compatibility
find_package(PkgConfig QUIET)

# Set CMAKE_PREFIX_PATH for Conan-generated files
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/generators ${CMAKE_PREFIX_PATH})

# Include Conan's generated target files directly (only CURL now, no nlohmann_json)
include(${CMAKE_BINARY_DIR}/generators/CURL-config.cmake OPTIONAL)

# Alternative: Load all available Conan targets
file(GLOB CONAN_CONFIGS "${CMAKE_BINARY_DIR}/generators/*-config.cmake")
foreach(config_file ${CONAN_CONFIGS})
    include(${config_file})
endforeach()

# Create library - handle both dummy.cpp and header-only scenarios
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dummy.cpp
)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src/dummy.cpp)
    add_library(AppwriteSDK INTERFACE)
    target_include_directories(AppwriteSDK 
        INTERFACE 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
    )
    set(LIBRARY_TYPE "INTERFACE")
else()
    add_library(AppwriteSDK ${SOURCES})
    target_include_directories(AppwriteSDK 
        PUBLIC 
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
    set(LIBRARY_TYPE "STATIC")
endif()

# Install headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include/AppwriteSDK)

# Install library only if not header-only
if(NOT LIBRARY_TYPE STREQUAL "INTERFACE")
    install(TARGETS AppwriteSDK
            ARCHIVE DESTINATION lib
            LIBRARY DESTINATION lib
            RUNTIME DESTINATION bin)
endif()

# Handle CURL target compatibility
set(CURL_TARGET "")
if(TARGET CURL::libcurl)
    set(CURL_TARGET CURL::libcurl)
    message(STATUS "Using CURL target: CURL::libcurl")
elseif(TARGET CURL::CURL)
    set(CURL_TARGET CURL::CURL)
    message(STATUS "Using CURL target: CURL::CURL")
else()
    message(STATUS "No CURL target found, continuing without it")
endif()

# Link libraries - ONLY CURL (nlohmann_json removed as per Issue #19)
if(CURL_TARGET)
    if(LIBRARY_TYPE STREQUAL "INTERFACE")
        target_link_libraries(AppwriteSDK INTERFACE ${CURL_TARGET})
    else()
        target_link_libraries(AppwriteSDK PUBLIC ${CURL_TARGET})
    endif()
endif()

# Windows-specific linking
if(WIN32)
    if(LIBRARY_TYPE STREQUAL "INTERFACE")
        target_link_libraries(AppwriteSDK INTERFACE ws2_32 wldap32 crypt32)
    else()
        target_link_libraries(AppwriteSDK PRIVATE ws2_32 wldap32 crypt32)
    endif()
endif()

# Status messages
message(STATUS "AppwriteSDK configured successfully")
message(STATUS "Library type: ${LIBRARY_TYPE}")
message(STATUS "CURL target: ${CURL_TARGET}")
message(STATUS "nlohmann_json removed as per Issue #19")
message(STATUS "CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")
