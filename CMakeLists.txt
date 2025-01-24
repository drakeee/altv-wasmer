﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("altv-client-js")

set(PROJECT_MODULE_NAME "altv-client-js")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DMODULE_NAME="${PROJECT_MODULE_NAME}")

if(UNIX)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/linux64/${CMAKE_BUILD_TYPE})
else()
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/win64/${CMAKE_BUILD_TYPE})
	# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
endif()
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

file(GLOB_RECURSE PROJECT_SOURCE_FILES "./src/*.h" "./src/*.hpp" "./src/*.cpp")

include_directories(
	#"${PROJECT_SOURCE_DIR}/src"
	"${PROJECT_SOURCE_DIR}/vendors/wasmer/include"
	"${PROJECT_SOURCE_DIR}/vendors/cpp-sdk"
)

add_library(
	${PROJECT_MODULE_NAME} SHARED
	${PROJECT_SOURCE_FILES}
)

target_compile_definitions(${PROJECT_MODULE_NAME} PRIVATE
	-DALT_CLIENT
	-DALT_CLIENT_API
	-DALTV_LUA_SHARED
)



add_library(
	${PROJECT_MODULE_NAME}-static STATIC
	${PROJECT_SOURCE_FILES}
)

target_compile_definitions(${PROJECT_MODULE_NAME}-static PRIVATE
	-DALT_CLIENT
	-DALT_CLIENT_API
	-DALTV_LUA_SHARED
)