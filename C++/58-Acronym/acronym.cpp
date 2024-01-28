// URL: https://exercism.org/tracks/cpp/exercises/acronym DATE: 2024-01-24

#include "acronym.h"


/**
 * Convert a given phrase to its acronym.
 *
 * @param phrase The input phrase to be converted.
 * @return The acronym generated from the input phrase.
 */
std::string acronym::acronym(std::string phrase) {
	std::string result;

	int phrase_length = phrase.length();
	int l = 0;

	while (l < phrase_length) {
		if (!isalnum(phrase[l])) {
			l++;
			continue;
		}

		int r = 0;

		while (r < phrase_length && (isalnum(phrase[l + r]) || phrase[l + r] == '\''))
			r++;

		if (phrase[l + r - 1] == '\'') // Words ending with an apostrophe
			r--;

		result += toupper(phrase[l]);

		l += r + 1;
	}

	return result;
}
