cmake_minimum_required(VERSION 3.16)

project(ApiCxx CXX)

option(SCREEPSXX_ENABLE_PCH "Enable precompiled headers" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(ApiCxx STATIC ${SOURCES})
target_include_directories(ApiCxx
		PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
		PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/Screeps
		)

set(COMPILE_FLAGS -sSTRICT=0)
set(LINK_FLAGS -sALLOW_MEMORY_GROWTH=1)
target_compile_options(ApiCxx PUBLIC ${COMPILE_FLAGS})
target_link_options(ApiCxx PUBLIC ${COMPILE_FLAGS} ${LINK_FLAGS})

if (SCREEPSXX_ENABLE_PCH)
	target_precompile_headers(ApiCxx PRIVATE
			<map>
			<memory>
			<optional>
			<string>
			<vector>
			<emscripten/val.h>
			)
endif()
