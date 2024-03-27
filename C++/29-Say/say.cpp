// URL: https://exercism.org/tracks/cpp/exercises/say DATE: 2023-12-24

#include <cmath>
#include <stdexcept>

#include "say.h"


/**
 * Converts certain numbers to their English representation.
 *
 *
 * @param n The number to be converted.
 * @return the English representation of the number.
 * @throws std::domain_error if he number is too large.
 */
std::string say::number_to_english(int n) {
	if (n >= 100)
		throw std::domain_error("The number is too large");

	switch (n) {
		case  1: return "one";
		case  2: return "two";
		case  3: return "three";
		case  4: return "four";
		case  5: return "five";
		case  6: return "six";
		case  7: return "seven";
		case  8: return "eight";
		case  9: return "nine";
		case 10: return "ten";
		case 11: return "eleven";
		case 12: return "twelve";
		case 13: return "thirteen";
		case 14: return "fourteen";
		case 15: return "fifteen";
		case 16: return "sixteen";
		case 17: return "seventeen";
		case 18: return "eighteen";
		case 19: return "nineteen";
		case 20: return "twenty";
		case 30: return "thirty";
		case 40: return "forty";
		case 50: return "fifty";
		case 60: return "sixty";
		case 70: return "seventy";
		case 80: return "eighty";
		case 90: return "ninety";

		default: return "";
	}
}

/**
 * Converts a chunk of a number to its English representation.
 *
 * This function takes an integer chunk and converts it to its English representation.
 * The chunk should be less than or equal to 999, otherwise a domain_error exception is thrown.
 *
 * @param n The integer chunk to be converted.
 * @return the English representation of the chunk.
 * @throws std::domain_error if the chunk is greater than 999.
 */
std::string say::chunk_to_english(int n) {
	if (n > 999)
		throw std::domain_error("The number is not a chunk");

	std::string translation;

	if (n >= 100) { // Hundreds
		translation += number_to_english(n / 100) + " hundred ";
		n %= 100;
	}

	if (n > 20) { // Tens and units
		translation += number_to_english(n - n % 10);
		n %= 10;
		translation += n ? '-' : ' ';
	}

	if (n > 0) // Tens and units
		translation += number_to_english(n) + ' ';

	return translation;
}

/**
 * Converts a given number to its English representation.
 *
 * This function takes a long long integer as input and converts it to its English representation.
 * The input number must be non-negative and less than or equal to 1 trillion (1,000,000,000,000).
 * If the input number is invalid, a std::domain_error exception is thrown.
 *
 * @param n The number to be converted to English.
 * @return the English representation of the input number.
 * @throws std::domain_error if the input number is invalid.
 */
std::string say::in_english(long long n) {
	if (n < 0 || 1'000'000'000'000 <= n)
		throw std::domain_error("invalid number");

	if (n == 0)
		return "zero";

	const std::string number_sections[] = {
		"",
		"thousand ", // 1'000
		"million ", // 1'000'000
		"billion ", // 1'000'000'000
	};

	std::string translation;

	for (int i = 3; i >= 0; i--) {
		long long section_value = pow(10, i * 3);

		if (n >= section_value) {
			int chunk = n / section_value;

			translation += chunk_to_english(chunk) + number_sections[i];

			n %= section_value;
		}
	}

	translation.pop_back();
	return translation;
}
