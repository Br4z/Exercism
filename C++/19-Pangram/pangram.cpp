// URL: https://exercism.org/tracks/cpp/exercises/pangram  DATE: 2023-12-09

#include <algorithm>
#include <bitset>
#include <cctype>

#include "pangram.h"


/**
 * Checks if a given sentence is a pangram.
 *
 * A pangram is a sentence that contains every letter of the alphabet
 * at least once.
 *
 * @param sentence The sentence to check.
 * @return True if the sentence is a pangram, false otherwise.
 */
bool pangram::is_pangram(const std::string &sentence) {
	std::bitset <26> alphabet;

	for (char c : sentence)
		if (isalpha(c))
			alphabet.set(tolower(c) - 'a');

	return alphabet.all();
}
