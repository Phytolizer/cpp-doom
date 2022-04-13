#include "doom.hpp"
#include "doom/types.hpp"

#include <iostream>
#include <span>
#include <string>

int main(int argc, const char** argv) {
	std::span args{argv, static_cast<Size>(argc)};
	Doom lib{args};
	return 0;
}
