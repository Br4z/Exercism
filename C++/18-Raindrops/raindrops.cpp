// URL: https://exercism.org/tracks/cpp/exercises/raindrops DATE: 2023-12-09

#include "raindrops.h"


/**
 * Converts a given number into a raindrop string.
 * If the number is divisible by 3, "Pling" is added to the result.
 * If the number is divisible by 5, "Plang" is added to the result.
 * If the number is divisible by 7, "Plong" is added to the result.
 * If none of the above conditions are met, the number itself is converted to a string and added to the result.
 *
 * @param number The number to be converted.
 * @return the raindrop string representation of the number.
 */
std::string raindrops::convert(int number) {
	std::string result;

	if (number % 3 == 0)
		result += "Pling";

	if (number % 5 == 0)
		result += "Plang";

	if (number % 7 == 0)
		result += "Plong";

	if (result == "")
		result = std::to_string(number);

	return result;
}
