# Set language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (build_release STREQUAL ON)
    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "-O2")
else ()
    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        # do nothing
    else ()
        set(CMAKE_BUILD_TYPE "Debug")
        set(CMAKE_CXX_FLAGS "-g") # debug symbol
        set(CMAKE_CXX_FLAGS "-O0")
    endif ()
endif ()

