// URL: https://exercism.org/tracks/cpp/exercises/binary DATE: 2024-01-26

#include <cmath>

#include "binary.h"


/**
 * Convert a binary number to its decimal equivalent.
 *
 * @param number The binary input string.
 * @return The decimal equivalent of the binary number.
 */
int binary::convert(std::string number) {
	int number_length = number.length();
	int result = 0;

	for (int i = 0; i < number_length; i++) {
		char character = number[i];

		if (character == '1' || character == '0')
			result += (character - '0') * pow(2, number_length - (i + 1));
		else
			return 0;
	}
	return result;
}