cmake_minimum_required (VERSION 3.10)
project(toto-check)

set(CMAKE_EXPORT_COMPILE_COMMANDS "on")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# options

option(TOTO_CHECK_ALL_WARNINGS            "toto-check: enable all compiler warnings" ON)
option(TOTO_CHECK_ALL_WARNINGS_3RD_PARTY  "toto-check: enable all compiler warnings in 3rd party libs" OFF)

option(TOTO_CHECK_SANITIZE_THREAD         "toto-check: enable thread sanitizer" OFF)
option(TOTO_CHECK_SANITIZE_ADDRESS        "toto-check: enable address sanitizer" OFF)
option(TOTO_CHECK_SANITIZE_UNDEFINED      "toto-check: enable undefined sanitizer" OFF)

# sanitizers

if (TOTO_CHECK_SANITIZE_THREAD)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=thread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif()

if (TOTO_CHECK_SANITIZE_ADDRESS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif()

if (TOTO_CHECK_SANITIZE_UNDEFINED)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=undefined")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
endif()

# main

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo")
endif ()

add_subdirectory(third-party)
add_subdirectory(src)
