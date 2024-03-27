// URL: https://exercism.org/tracks/cpp/exercises/resistor-color DATE: 2024-02-06

#include "resistor_color.h"


/**
 * Returns the numerical value associated with a particular color band.
 *
 * @param color The color of the resistor band.
 * @return the numerical value associated with the color band.
 */
int resistor_color::color_code(std::string color) {
	for (int i = 0; i < (int) colors_vector.size(); i++)
		if (colors_vector[i] == color)
			return i;

	return -1;
}

/**
 * Returns the different color bands for resistors.
 *
 * @return a vector of resistor color bands.
 */
std::vector <std::string> resistor_color::colors() {
	return colors_vector;
}
