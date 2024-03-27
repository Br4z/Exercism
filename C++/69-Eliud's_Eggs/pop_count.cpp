// URL: https://exercism.org/tracks/cpp/exercises/eliuds-eggs DATE: 2024-01-30

#include <string>

#include "pop_count.h"


/**
 * Count the occurrences of a character in a string.
 *
 * @param string The input string.
 * @param character The character to count.
 * @return the number of occurrences of the character in the string.
 */
int count_character(std::string string, char character) {
	int count = 0;

	for (char string_character : string)
		if (string_character == character)
			count++;

	return count;
}

/**
 * Convert a decimal number to its binary representation.
 *
 * @param number The decimal number to convert.
 * @return the binary representation of the decimal number.
 */
std::string decimal_to_binary(int number) {
	std::string result = "";

	do {
		result = result + std::to_string(number % 2);
		number = (number - number % 2) / 2;
	} while (number > 0);

	return result;
}

/**
 * Count the number of eggs in the coop based on the binary representation
 * of positions.
 *
 * @param decimal The decimal number representing the binary positions of
 * potential egg-laying spots.
 * @return the number of actual eggs in the coop.
 */
int chicken_coop::positions_to_quantity(int decimal) {
	std::string binary = decimal_to_binary(decimal);

	return count_character(binary, '1');
}
