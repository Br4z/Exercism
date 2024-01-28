// URL: https://exercism.org/tracks/cpp/exercises/isogram DATE: 2024-01-27

#include "isogram.h"


/**
 * Converts a string to lowercase.
 *
 * @param string The input string to be converted.
 * @return The converted string in lowercase.
 */
std::string to_lower(const std::string& string) {
	std::string result;

	for (int i = 0; i < (int) string.length(); i++)
		result += tolower(string[i]);

	return result;
}

/**
 * Determine if a word or phrase is an isogram.
 *
 * @param text The input word or phrase to be checked.
 * @return True if the input is an isogram, false otherwise.
 */
bool isogram::is_isogram(std::string text) {
	text = to_lower(text);
	std::string letters = "";

	for (char &character : text) {
		if (character == ' ' || character == '-' || character == '_')
			continue;
		else if (letters.find(character) == std::string::npos)
			letters += character;
		else
			return false;
	}

	return true;
}
