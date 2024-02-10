// URL: https://exercism.org/tracks/cpp/exercises/scrabble-score DATE: 2024-01-29

#include <map>
#include <vector>

#include "scrabble_score.h"


/**
 * Converts a string to uppercase.
 *
 * @param string The input string to be converted.
 * @return The converted string in uppercase.
 */
std::string to_upper(const std::string& string) {
	std::string result;

	for (int i = 0; i < (int) string.length(); i++)
		result += toupper(string[i]);

	return result;
}

std::map <std::vector <char>, int> scores{
	{ { 'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T' }, 1 },
	{ { 'D', 'G' }, 2 },
	{ { 'B', 'C', 'M', 'P' }, 3},
	{ { 'F', 'H', 'V', 'W', 'Y' }, 4},
	{ { 'K' }, 5},
	{ { 'J', 'X' }, 8},
	{ { 'Q', 'Z' }, 10},
};

/**
 * Check if a vector includes a specific element.
 *
 * @param T The type of elements in the vector.
 * @param vector The vector to check.
 * @param element The element to check for inclusion.
 * @return True if the vector includes the element, false otherwise.
 */
template <typename T>
bool includes(std::vector <T> vector, T element) {
	for (const T& vector_element : vector)
		if (vector_element == element)
			return true;

	return false;
}

/**
 * Compute the Scrabble score for a given word.
 *
 * @param word The input word to compute the score for.
 * @return The Scrabble score for the given word.
 */
int scrabble_score::score(std::string word) {
	int sum = 0;
	word = to_upper(word);

	for (const char& letter : word)
		for (const auto& score : scores)
			if (includes(score.first, letter))
				sum += score.second;

	return sum;
}
