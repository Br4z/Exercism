// URL: https://exercism.org/tracks/cpp/exercises/etl DATE: 2024-01-19

#include "etl.h"


/**
 * Transform the data structure containing letters and their point values.
 *
 * @param old The old data structure containing letters grouped by score.
 * @return The new data structure containing individual letters with their scores.
 */
std::map <char, int> etl::transform(std::map <int, std::vector <char>> old) {
	std::map <char, int> result;

	for (const auto& pair : old) { // std::pair <int, std::vector <char>>
		int points = pair.first;
		std::vector <char> characteres = pair.second;

		for (const char& character : characteres)
			result[character | 32] = points;
	}

	return result;
}
