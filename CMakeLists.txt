project( libart )
cmake_minimum_required( VERSION 3.5 )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -march=native -g")
# single-thread
include_directories(single_thread)
add_executable( libart1 single_thread/app.c single_thread/art.c )

# multi-thread
#list(APPEND CMAKE_MODULE_PATH ".")
find_package(JEMALLOC)
find_package(TBB)
find_package (Threads)

set(ART_FILES multi_thread/OptimisticLockCoupling/Tree.cpp multi_thread/ROWEX/Tree.cpp multi_thread/ART/Tree.cpp)
add_library(ARTSynchronized ${ART_FILES})
target_link_libraries(ARTSynchronized tbb jemalloc ${CMAKE_THREAD_LIBS_INIT})

set(SOURCE_FILES multi_thread/example.cpp)
add_executable(example ${SOURCE_FILES})
target_link_libraries(example ARTSynchronized)


