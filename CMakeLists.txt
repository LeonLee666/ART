project( libart )
cmake_minimum_required( VERSION 3.5 )
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -march=native -g")
# single-thread
include_directories(single_thread)
set(FILES1 single_thread/app.c single_thread/art.c )
add_executable( libart1 ${FILES1} )
#########################
find_package(Jemalloc)
find_package(TBB)
find_package (Threads)
set(FILES2 multi_thread/OptimisticLockCoupling/Tree.cpp multi_thread/ROWEX/Tree.cpp multi_thread/ART/Tree.cpp)
add_library(ARTlib ${FILES2})
target_link_libraries(ARTlib tbb jemalloc ${CMAKE_THREAD_LIBS_INIT})
##########################
set(FILES3 multi_thread/example.cpp)
add_executable(libart2 ${FILES3})
target_link_libraries(libart2 ARTlib)


