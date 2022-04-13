# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(cpp-doomTests LANGUAGES CXX)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(cpp-doom_test source/catch_main.cpp source/cpp-doom_test.cpp)
target_link_libraries(cpp-doom_test PRIVATE cpp-doom_lib Catch2::Catch2)
target_compile_features(cpp-doom_test PRIVATE cxx_std_20)

catch_discover_tests(cpp-doom_test)

# ---- End-of-file commands ----

add_folders(Test)
