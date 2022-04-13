#include "doom.hpp"

#include <fmt/core.h>

Doom::Doom(std::span<const char*> args) : m_misc(*this) {
	m_args = std::vector<std::string>(args.begin(), args.end());
}

Doom::MiscState& Doom::Misc() {
	return m_misc;
}

Doom::MiscState::MiscState(Doom& doom) : m_doom(doom) {}

std::optional<Size> Doom::MiscState::CheckParm(std::string_view parm) {
	for (Size i = 1; i < m_doom.m_args.size(); ++i) {
		if (m_doom.m_args[i] == parm) {
			return i;
		}
	}
	return {};
}
