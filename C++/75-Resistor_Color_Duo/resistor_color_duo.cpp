// URL: https://exercism.org/tracks/cpp/exercises/resistor-color-duo DATE: 2024-02-06

#include "resistor_color_duo.h"


/**
 * Returns the numerical value associated with a particular color band.
 *
 * @param color The color of the resistor band.
 * @return the numerical value associated with the color band.
 */
int resistor_color_duo::color_code(std::string color) {
	for (int i = 0; i < (int) colors_vector.size(); i++)
		if (colors_vector[i] == color)
			return i;

	return -1;
}

/**
 * Returns a two-digit number representing the resistance value of the resistor
 * based on the color bands.
 *
 * @param pair A vector containing two color bands of the resistor.
 * @return the two-digit number representing the resistance value.
 */
int resistor_color_duo::value(std::vector <std::string> pair) {
	std::string number = std::to_string(color_code(pair[0])) + std::to_string(color_code(pair[1]));

	return std::stoi(number);
}
