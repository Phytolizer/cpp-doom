#pragma once

#include "doom/types.hpp"

#include <optional>
#include <span>
#include <string>
#include <string_view>
#include <vector>

/**
 * @brief The core implementation of the executable
 *
 * This class makes up the library part of the executable, which means that the
 * main logic is implemented here. This kind of separation makes it easy to
 * test the implementation for the executable, because the logic is nicely
 * separated from the command-line logic implemented in the main function.
 */
class Doom {
	std::vector<std::string> m_args;

  public:
	/**
	 * @brief Construct a new Doom object
	 *
	 * @param args The command-line arguments
	 */
	explicit Doom(std::span<const char*> args);

	class MiscState {
		Doom& m_doom;

		friend class Doom;
		explicit MiscState(Doom& doom);

	  public:
		std::optional<Size> CheckParm(std::string_view parm);
	};

  private:
	MiscState m_misc;

  public:
	MiscState& Misc();
};
