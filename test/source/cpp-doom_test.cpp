#include "lib.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Name is cpp-doom", "[library]") {
	library lib;
	REQUIRE(lib.name == "cpp-doom");
}
