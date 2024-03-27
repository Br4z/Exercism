// URL: https://exercism.org/tracks/cpp/exercises/resistor-color DATE: 2024-02-06

#include <string>
#include <vector>

#ifndef RESISTOR_COLOR_H
#define RESISTOR_COLOR_H


namespace resistor_color {
	const std::vector <std::string> colors_vector = {
		"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"
	};

	int color_code(std::string color);
	std::vector <std::string> colors();
}

#endif
