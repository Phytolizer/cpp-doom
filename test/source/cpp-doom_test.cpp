#include "doom.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Args are kept correctly", "[library]") {
	std::vector args{"doom", "--help", "--version"};
	Doom lib{args};

	REQUIRE(lib.Misc().CheckParm("--help") == 1);
	REQUIRE(lib.Misc().CheckParm("--version") == 2);
}
