#include "lib.hpp"

#include <fmt/core.h>

Library::Library() : m_name(fmt::format("{}", "cpp-doom")) {}

const std::string& Library::Name() const {
	return m_name;
}
