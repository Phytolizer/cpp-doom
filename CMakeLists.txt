cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
	cpp-doom
	VERSION 0.1.0
	DESCRIPTION "Short description"
	HOMEPAGE_URL "https://example.com/"
	LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(cpp-doom_lib OBJECT source/doom.cpp)

target_include_directories(
	cpp-doom_lib ${warning_guard}
	PUBLIC "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(cpp-doom_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(cpp-doom_lib PRIVATE fmt::fmt)

# ---- Declare executable ----

add_executable(cpp-doom_exe source/main.cpp)
add_executable(cpp-doom::exe ALIAS cpp-doom_exe)

set_target_properties(
	cpp-doom_exe PROPERTIES OUTPUT_NAME cpp-doom EXPORT_NAME exe
)

target_compile_features(cpp-doom_exe PRIVATE cxx_std_20)

target_link_libraries(cpp-doom_exe PRIVATE cpp-doom_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
	include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT cpp-doom_DEVELOPER_MODE)
	return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
	message(
		AUTHOR_WARNING "Developer mode is intended for developers of cpp-doom"
	)
endif()

include(cmake/dev-mode.cmake)
