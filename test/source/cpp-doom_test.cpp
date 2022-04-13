#include "lib.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Name is cpp-doom", "[library]") {
	Library lib;
	REQUIRE(lib.Name() == "cpp-doom");
}
