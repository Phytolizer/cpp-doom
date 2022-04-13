#include "lib.hpp"

#include <iostream>
#include <string>

auto main() -> int {
	Library lib;
	std::string message = "Hello from " + lib.Name() + "!";
	std::cout << message << '\n';
	return 0;
}
