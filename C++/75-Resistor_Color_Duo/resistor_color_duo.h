// URL: https://exercism.org/tracks/cpp/exercises/resistor-color-duo DATE: 2024-02-06

#include <string>
#include <vector>

#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H


namespace resistor_color_duo {
	const std::vector <std::string> colors_vector = {
		"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"
	};

	int color_code(std::string color);
	int value(std::vector <std::string> pair);
}

#endif
