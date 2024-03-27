// URL: https://exercism.org/tracks/cpp/exercises/isbn-verifier DATE: 2024-01-30

#include "isbn_verifier.h"


/**
 * Remove dashes from the given string.
 *
 * @param string The input string with or without dashes.
 * @return the string with dashes removed.
 */
std::string clean_dashes(std::string &string) {
	std::string result;

	for (const char& character : string)
		if (character != '-')
			result += character;

	return result;
}

/**
 * Check if the provided string is a valid ISBN-10.
 *
 * @param identification The ISBN-10 string to be checked.
 * @return true if the ISBN-10 is valid, false otherwise.
 */
bool isbn_verifier::is_valid(std::string identification) {
	identification = clean_dashes(identification);

	int sum = 0;

	if (identification.length() != 10)
		return false;

	for (int i = 0; i < 10; i++) {
		char character = identification[i];
		int d;

		if (character == 'X')
			if (i == 9)
				d = 10;
			else
				return false;
		else
			d = character - '0';

		sum += d * (10 - i);
	}

	return sum % 11 == 0;
}
