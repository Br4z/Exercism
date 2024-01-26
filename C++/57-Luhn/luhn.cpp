// URL: https://exercism.org/tracks/cpp/exercises/luhnluhn DATE: 2024-01-23

#include "luhn.h"


/**
 * Delete spaces from the input string.
 *
 * @param input The input string.
 * @return The input string with spaces removed.
 */
std::string delete_spaces(std::string string) {
	std::string result;

	for (char &character : string)
		if (character != ' ')
			result += character;

	return result;
}

/**
 * Validate a given identification number using the Luhn algorithm.
 *
 * @param identification The identification number to be validated.
 * @return True if the identification number is valid, false otherwise.
 */
bool luhn::valid(std::string identification) {
	identification = delete_spaces(identification);
	int identification_length = identification.length();

	if (identification_length <= 1)
		return false;

	int sum = 0;
	bool even_positions = identification_length % 2;

	for (int i = 0; i < identification_length; i++) {
		char character = identification[i];

		if ('0' <= character && character <= '9')
			if ((i + even_positions) % 2 == 0)
				sum += (character - '0') * 2 - (character > '4' ? 9 : 0);
			else
				sum += character - '0';
		else
			return false;
	}

	return sum % 10 == 0;
}
