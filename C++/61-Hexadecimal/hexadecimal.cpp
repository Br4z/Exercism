// URL: https://exercism.org/tracks/cpp/exercises/hexadecimal DATE: 2024-01-26

#include <cmath>

#include "hexadecimal.h"


/**
 * Convert a hexadecimal number to its decimal equivalent.
 *
 * @param number The hexadecimal input string.
 * @return The decimal equivalent of the hexadecimal number.
 */
int hexadecimal::convert(std::string number) {
	int number_length = number.length();
	int result = 0;

	for (int i = 0; i < number_length; i++) {
		char character = number[i];

		if ('0'<= character && character <= '9')
			result += (character - '0') * pow(16, number_length - (i + 1));
		else if ('a'<= character && character <= 'f')
			result += ((character - 'a') + 10) * pow(16, number_length - (i + 1));
		else
			return 0;
	}

	return result;
}
