The Go-verushash implementation is experimental software. Use it at your own risk.

This is preliminary work and subject to change.

Copyright 2020 VerusCoin Developers

---

# Overview

[Go-verushash](https://github.com/asherda/Go-verushash) is an implementation of the VerusCoin hash algorithms in C++ wrapped using swig to allow access from go 

The C++ source modules are identical with those used in the [verusd](https://giuthub.com/VerusCoin/VerusCoin) peer to peer daemon. The hash is current as of the V2b2 version, supporting that and all prior hashes.

# Local/Developer Usage

Dependencies: cmake, go, swig, protoc, c++

Install [Cmake](https://cmake.org/download/)

Install [Go](https://golang.org/dl/#stable) version 1.11 or later. You can see your current version by running `go version`.

## Getting Started
First clone the archive and run cmake
```
~$ git clone git@github.com:Asherda/Go-VerusHash.git
Cloning into 'Go-VerusHash'...
remote: Enumerating objects: 67, done.
remote: Counting objects: 100% (67/67), done.
remote: Compressing objects: 100% (56/56), done.
remote: Total 67 (delta 10), reused 64 (delta 7), pack-reused 0
Receiving objects: 100% (67/67), 297.82 KiB | 7.26 MiB/s, done.
Resolving deltas: 100% (10/10), done.
~$ cd Go-VerusHash/
~/Go-VerusHash$ cmake .
-- The C compiler identification is GNU 8.4.0
-- The CXX compiler identification is GNU 8.4.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Boost version: 1.65.1
-- Found the following Boost libraries:
--   system
-- Found PkgConfig: /usr/bin/pkg-config (found version "0.29.1") 
-- Checking for module 'libsodium'
--   Found libsodium, version 1.0.16
-- CXXFLAGS:  -std=c++11 -march=x86-64 
-- LIBS: /usr/lib/x86_64-linux-gnu/libboost_system.a
-- Configuring done
-- Generating done
-- Build files have been written to: /home/virtualsoundnw/Go-VerusHash
~/Go-VerusHash$
```
Now that you've generated the Makefile, run make repeatedly each time you change naything, no need to repeat cmake:
```
~/Go-VerusHash$ make
Scanning dependencies of target verushash
[  6%] Building C object CMakeFiles/verushash.dir/src/haraka.c.o
[ 12%] Building C object CMakeFiles/verushash.dir/src/haraka_portable.c.o
[ 18%] Building CXX object CMakeFiles/verushash.dir/src/uint256.cpp.o
[ 25%] Building CXX object CMakeFiles/verushash.dir/src/utilstrencodings.cpp.o
[ 31%] Building CXX object CMakeFiles/verushash.dir/src/verus_hash.cpp.o
[ 37%] Building CXX object CMakeFiles/verushash.dir/src/verus_clhash.cpp.o
[ 43%] Building CXX object CMakeFiles/verushash.dir/src/verus_clhash_portable.cpp.o
[ 50%] Building CXX object CMakeFiles/verushash.dir/src/ripemd160.cpp.o
[ 56%] Building CXX object CMakeFiles/verushash.dir/src/sha256.cpp.o
[ 62%] Building CXX object CMakeFiles/verushash.dir/compat/glibc_compat.cpp.o
[ 68%] Building CXX object CMakeFiles/verushash.dir/compat/glibc_sanity.cpp.o
[ 75%] Building CXX object CMakeFiles/verushash.dir/compat/glibcxx_sanity.cpp.o
[ 81%] Building CXX object CMakeFiles/verushash.dir/compat/strnlen.cpp.o
[ 87%] Building CXX object CMakeFiles/verushash.dir/support/cleanse.cpp.o
[ 93%] Building CXX object CMakeFiles/verushash.dir/blockhash.cpp.o
[100%] Linking CXX static library libverushash.a
[100%] Built target verushash
~/Go-VerusHash$
```
If everything worked you now have the library file in the projects root directory.
```
~/Go-VerusHash$ ls -l libverushash.a 
-rw-r--r-- 1 virtualsoundnw virtualsoundnw 1059760 Aug 19 22:18 libverushash.a
~/Go-VerusHash$ 
``` 
Usually you simply import this module directly from github into your golang module, so you won't need to do all of the above steps unless you are actually working on the Go-VerusHash code directly.
# Using Go_VerusHash
Import Go-VerusHash into your golang modules to access the verushash method.
.
