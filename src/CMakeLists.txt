if (TOTO_CHECK_ALL_WARNINGS)
    if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
    else()
        # todo : windows
    endif()
endif()

add_executable(reload-archive-6-49 reload-archive-6-49.cpp)
add_executable(check-cli-6-49 check-cli-6-49.cpp)

add_executable(check-ws-6-49 check-ws-6-49.cpp)
target_link_libraries(check-ws-6-49 incppect)
