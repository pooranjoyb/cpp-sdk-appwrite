cmake_minimum_required(VERSION 3.15)
project(AppwriteSDK VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
    add_definitions(-DNOMINMAX)
endif()

find_package(PkgConfig QUIET)

# Ensure CMake uses Conan's find modules for dependencies
if(EXISTS "${CMAKE_BINARY_DIR}/generators/CURLConfig.cmake")
    list(PREPEND CMAKE_PREFIX_PATH "${CMAKE_BINARY_DIR}/generators")
endif()

find_package(CURL REQUIRED)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp" "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_library(AppwriteSDK STATIC ${SOURCES})

target_include_directories(AppwriteSDK 
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(TARGET CURL::libcurl)
    target_link_libraries(AppwriteSDK PUBLIC CURL::libcurl)
    message(STATUS "AppwriteSDK: Linked with CURL::libcurl")
elseif(TARGET CURL::CURL)
    target_link_libraries(AppwriteSDK PUBLIC CURL::CURL)
    message(STATUS "AppwriteSDK: Linked with CURL::CURL")
else()
    message(FATAL_ERROR "CURL library not found! Ensure Conan CMakeDeps configured correctly.")
endif()

if(WIN32)
    target_link_libraries(AppwriteSDK PRIVATE ws2_32 wldap32 crypt32)
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include/AppwriteSDK
)
install(TARGETS AppwriteSDK
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

message(STATUS "AppwriteSDK: Ready for install, all dependencies resolved.")
