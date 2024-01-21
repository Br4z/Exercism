// URL: https://exercism.org/tracks/cpp/exercises/anagramanagram DATE: 2024-01-21

#include "anagram.h"


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
 * Check if a given candidate word is an anagram of the target word.
 *
 * @param candidate The candidate word to be checked for being an anagram.
 * @return True if the candidate is an anagram, false otherwise.
 */
bool anagram::anagram::is_anagram(std::string candidate) {
	if (word == candidate || word.length() != candidate.length())
		return false;

	for (char &letter : word) {
		int index = candidate.find(letter);

		if (index != std::string::npos)
			candidate[index] = ' ';
		else
			return false;
	}

	return true;
}

anagram::anagram::anagram(std::string word) : word(to_lower(word)) {

}

/**
 * Find the anagram set from a set of candidate words.
 *
 * @param candidates A vector of candidate words.
 * @return A vector of words that are anagrams of the target word.
 */
std::vector <std::string> anagram::anagram::matches(std::vector <std::string> candidates) {
	std::vector <std::string> anagrams;

	for (std::string candidate : candidates)
		if (is_anagram(to_lower(candidate)))
			anagrams.push_back(candidate);

	return anagrams;
}
