// URL: https://exercism.org/tracks/cpp/exercises/yacht DATE: 2024-02-21

#include "yacht.h"


/**
 * Analyzes the provided dice values and counts the occurrences of each value.
 *
 * @param dices The values of the dice.
 * @return a map containing the count of each dice value.
 */
std::map <int, int> yacht::analyze_dices(const std::vector <int> &dices) {
	std::map <int, int> result;

	for (const int& dice: dices)
		result[dice]++;

	return result;
}

/**
 * Calculates the score for the given dice values and category.
 *
 * @param dices The values of the dice.
 * @param category The scoring category.
 * @return the score for the specified category and dice values.
 */
int yacht::score(std::vector <int> dices, std::string category) {
	std::map <int, int> analyzed_dices = analyze_dices(dices);

	if (category == "ones")
		return analyzed_dices[1] * 1;
	else if (category == "twos")
		return analyzed_dices[2] * 2;
	else if (category == "threes")
		return analyzed_dices[3] * 3;
	else if (category == "fours")
		return analyzed_dices[4] * 4;
	else if (category == "fives")
		return analyzed_dices[5] * 5;
	else if (category == "sixes")
		return analyzed_dices[6] * 6;
	else if (category == "full house") {
		if (analyzed_dices.size() == 2) {
			int result = 0;

			for (std::pair <const int, int>& dice : analyzed_dices)
				if (dice.second == 3 || dice.second == 2)
					result += dice.first * dice.second;
				else
					return 0;

			return result;
		} else
			return 0;
	} else if (category == "four of a kind") {
		for (std::pair <const int, int>& dice : analyzed_dices)
			if (dice.second >= 4)
				return dice.first * 4;

		return 0;
	} else if (category == "little straight") {
		if (analyzed_dices.size() == 5) {
			std::map <int, int>::iterator search = analyzed_dices.find(6);

			return search == analyzed_dices.end() ? 30 : 0;
		} else
			return 0;
	} else if (category == "big straight") {
		if (analyzed_dices.size() == 5) {
			std::map <int, int>::iterator search = analyzed_dices.find(1);

			return search == analyzed_dices.end() ? 30 : 0;
		} else
			return 0;
	} else if (category == "choice") {
		int result = 0;

		for (std::pair <const int, int>& dice : analyzed_dices)
			result += dice.first * dice.second;

		return result;
	} else
		return analyzed_dices.size() == 1 ? 50 : 0;
}
