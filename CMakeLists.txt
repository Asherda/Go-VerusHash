cmake_minimum_required(VERSION 3.10)
project(verushash)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # -Wall
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(verushash STATIC
        src/haraka.c
        src/haraka_portable.c
        src/uint256.cpp
        src/utilstrencodings.cpp
        src/verus_hash.cpp
        src/verus_clhash.cpp
        src/verus_clhash_portable.cpp
        src/ripemd160.cpp
        src/sha256.cpp
        compat/glibc_compat.cpp
        compat/glibc_sanity.cpp
        compat/glibcxx_sanity.cpp
        compat/strnlen.cpp
        support/cleanse.cpp
        blockhash.cpp
        )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64 -Wno-unused-result")

    # optimizations
    add_definitions(-O2)


# MACOS
if(APPLE)
   include_directories(${CMAKE_CURRENT_SOURCE_DIR}/compat)
endif(APPLE)

set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/src/verus_hash.cpp PROPERTIES COMPILE_FLAGS "-m64 -mpclmul -msse2 -msse3 -mssse3 -msse4 -msse4.1 -msse4.2 -maes -g -fomit-frame-pointer")
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/src/verus_clhash.cpp PROPERTIES COMPILE_FLAGS "-m64 -mpclmul -msse2 -msse3 -mssse3 -msse4 -msse4.1 -msse4.2 -maes -g -fomit-frame-pointer")
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/src/haraka.c PROPERTIES COMPILE_FLAGS "-m64 -mpclmul -msse2 -msse3 -mssse3 -msse4 -msse4.1 -msse4.2 -maes -g -fomit-frame-pointer")

# Common
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# BOOST
#find_package(Threads REQUIRED COMPONENTS)
# compile boost statically
set(Boost_USE_STATIC_LIBS ON)
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
#set(BUILD_SHARED_LIBRARIES OFF)
#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
find_package(Boost REQUIRED COMPONENTS system)

if (Boost_FOUND)
    # From the official documentation:
    # Add include directories to the build. [...] If the SYSTEM option is given,
    # the compiler will be told the directories are meant as system include
    # directories on some platforms (signalling this setting might achieve effects
    # such as the compiler skipping warnings [...])."
    include_directories (SYSTEM ${Boost_INCLUDE_DIR})

    # From the official documentation:
    # "Specify directories in which the linker will look for libraries. [...] Note
    # that this command is rarely necessary. Library locations returned by
    # find_package() and find_library() are absolute paths. Pass these absolute
    # library file paths directly to the target_link_libraries() command. CMake
    # will ensure the linker finds them."
    link_directories (${Boost_LIBRARY_DIRS})
else()
    message("Boost_FOUND NOT FOUND")
endif ()

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSODIUM libsodium)

if(STATIC_LIBSODIUM)
  if(BUILD_STATIC_EXECUTABLES)
    set_target_properties(verushash PROPERTIES LINK_SEARCH_START_STATIC 1)
    set_target_properties(verushash PROPERTIES LINK_SEARCH_END_STATIC 1)
  endif()
  set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
endif()

find_path(SODIUM_INCLUDE_DIR sodium.h HINTS ${LIBSODIUM_INCLUDE_DIRS} /usr/local/include /opt/local/include /opt/include)
find_library(SODIUM_LIBRARY NAMES sodium HINTS ${LIBSODIUM_LIBRARY_DIRS} /usr/local/lib /opt/local/lib /opt/lib)

if(STATIC_LIBSODIUM)
  set(LIBSODIUM_CFLAGS_OTHER ${LIBSODIUM_STATIC_CFLAGS_OTHER})
  set(LIBSODIUM_LDFLAGS_OTHER ${LIBSODIUM_STATIC_LDFLAGS_OTHER})
endif()

target_include_directories(verushash PUBLIC ${SODIUM_INCLUDE_DIR})
target_compile_options(verushash PUBLIC ${LIBSODIUM_CFLAGS} ${LIBSODIUM_CFLAGS_OTHER})
target_link_libraries(verushash ${SODIUM_LIBRARY} ${LIBSODIUM_LDFLAGS_OTHER})

set(LIBS ${LIBS} ${Boost_LIBRARIES})

message("-- CXXFLAGS: ${CMAKE_CXX_FLAGS}")
message("-- LIBS: ${LIBS}")

target_link_libraries (verushash ${LIBS})
