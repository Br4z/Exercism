// URL: https://exercism.org/tracks/cpp/exercises/run-length-encoding DATE: 2024-02-04

#include "run_length_encoding.h"


/**
 * Encodes a given string using run-length encoding.
 * Each run of consecutive identical characters is replaced with a count
 * followed by the character.
 *
 * @param input The string to be encoded.
 * @return the run-length encoded string.
 */
std::string run_length_encoding::encode(std::string input) {
	std::string result = "";
	int input_length = input.length();
	char character = input[0];

	int i = 0, count;

	while (i < input_length) {
		count = 1;

		while (count < input_length - i && input[i + count] == character)
			count++;

		result += (count == 1 ? "" : std::to_string(count)) + character;
		character = input[i + count];

		i += count;
	}

	return result;
}

/**
 * Decodes a run-length encoded string and returns the original string.
 * Each run of consecutive identical characters is represented by a count
 * followed by the character.
 *
 * @param input The run-length encoded string.
 * @return the decoded original string.
 */
std::string run_length_encoding::decode(std::string input) {
	std::string result = "";
	int input_length = input.length();

	int l = 0, count = 1;

	while (l < input_length) {
		int r = 0;

		if (!isdigit(input[l])) {
			result += input[l];
			l++;
			continue;
		}

		while (l + r < input_length && isdigit(input[l + r]))
			r++;

		count = std::stoi(input.substr(l, r)); // [l, l + r - 1]
		char character = input[l + r];
		result += std::string(count, character);

		l += r + 1;
	}

	return result;
}
