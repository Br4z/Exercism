// URL: https://exercism.org/tracks/cpp/exercises/rotational-cipher DATE: 2024-02-05

#include "rotational_cipher.h"


/**
 * Rotates each letter in the input string by a given displacement value
 * using the rotational cipher.
 *
 * @param input The string to be rotated.
 * @param displacement The number of positions each letter should be shifted.
 * @return The rotated string.
 */
std::string rotational_cipher::rotate(std::string input, int displacement) {
	for (char &character : input)
		if (isalpha(character)) {
			char base = isupper(character) ? 'A' : 'a';

			character = (char) ((character - base + displacement) % 26 + base);
		}

	return input;
}
