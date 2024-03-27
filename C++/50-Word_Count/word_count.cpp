// URL: https://exercism.org/tracks/cpp/exercises/word-count DATE: 2024-01-16

#include "word_count.h"


/**
 * Converts all characters in the given string to lowercase.
 *
 * @param sentence The string to be converted to lowercase.
 */
void to_lowercase(std::string &sentence) {
	for (int i = 0; i < (int) sentence.length(); i++)
		sentence[i] = tolower(sentence[i]);
}

/**
 * Count the occurrences of each word in a subtitle of a drama.
 *
 * @param sentence The subtitle string.
 * @return a map containing word counts.
 */
std::map <std::string, int> word_count::words(std::string sentence) {
	std::map <std::string, int> histrogram;
	int sentence_length = sentence.length();

	to_lowercase(sentence);

	int l = 0;

	while (l < sentence_length) {
		if (!isalnum(sentence[l])) {
			l++;
			continue;
		}

		int r = 0;

		while (r < sentence_length && (isalnum(sentence[l + r]) || sentence[l + r] == '\''))
			r++;

		if (sentence[l + r - 1] == '\'') // Words ending with an apostrophe
			r--;

		histrogram[sentence.substr(l, r)]++;

		l += r + 1;
	}

	return histrogram;
}
