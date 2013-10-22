find_package (Boost REQUIRED COMPONENTS
	system)
include_directories (${Boost_INCLUDE_DIRS})
add_executable (test1 test1.cpp)
target_link_libraries (test1 ${Boost_LIBRARIES})
