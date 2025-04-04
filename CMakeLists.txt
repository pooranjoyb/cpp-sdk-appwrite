cmake_minimum_required(VERSION 3.10)
project(AppwriteSDK CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_BINARY_DIR}/conan/include)
link_directories(${CMAKE_BINARY_DIR}/conan/lib)

find_package(CURL REQUIRED)

set(SRCS
    src/Appwrite.cpp
    src/services/Account.cpp
    src/services/Query.cpp
    src/services/Databases.cpp
    src/services/Storage.cpp
    src/services/Health.cpp
    src/Utils.cpp
    src/Validator.cpp
)

add_library(AppwriteSDK STATIC ${SRCS})

include_directories(include)

target_link_libraries(AppwriteSDK CURL::libcurl)

set_target_properties(AppwriteSDK PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

set(HEADERS
    include/Appwrite.hpp
    include/classes/Account.hpp
    include/classes/Query.hpp
    include/classes/Databases.hpp
    include/classes/Storage.hpp
    include/classes/Health.hpp
    include/config/Config.hpp
    include/enums/HttpStatus.hpp
    include/exceptions/AppwriteException.hpp
    include/Utils.hpp
    include/Validator.hpp
)

install(DIRECTORY include/ DESTINATION /usr/local/include/AppwriteSDK)
install(FILES ${HEADERS} DESTINATION /usr/local/include/AppwriteSDK)
install(TARGETS AppwriteSDK ARCHIVE DESTINATION /usr/local/lib)
