// URL: https://exercism.org/tracks/cpp/exercises/kindergarten-garden DATE: 2024-02-17

#include <array>
#include <string>

#ifndef KINDERGARTEN_GARDEN_H
#define KINDERGARTEN_GARDEN_H


namespace kindergarten_garden {
	enum class Plants {
		clover,
		grass,
		violets,
		radishes
	};

	Plants get_plant(char letter);
	std::array <Plants, 4> plants(std::string garden, std::string student);
}

#endif
