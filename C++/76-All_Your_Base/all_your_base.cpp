// URL: https://exercism.org/tracks/cpp/exercises/all-your-base DATE: 2024-02-07

#include <cmath>
#include <stdexcept>

#include "all_your_base.h"


/**
 * Converts a number from a given base to decimal.
 *
 * @param actual_base The base of the input number.
 * @param digits A vector containing the digits of the input number.
 * @return the decimal representation of the input number.
 *
 * @throws std::invalid_argument if the input digit is invalid for the given base.
 */
int to_decimal(int actual_base, std::vector <unsigned int> digits) {
	int result = 0;
/* 	int max_powder = digits.size() - 1;

	for (int i = 0; i <= max_powder; i++) {
		int digit = digits[i];

		if (digit >= actual_base)
			throw std::invalid_argument("Invalid digit \"" + std::to_string(digit) + "\" for a " + std::to_string(actual_base) + " base");
		else {
			int powder = max_powder - i;
			result += digits[i] * pow(actual_base, powder);
		}
	} */

	for (unsigned int digit : digits)
		if (digit >= actual_base)
			throw std::invalid_argument("Invalid digit \"" + std::to_string(digit) + "\" for a " + std::to_string(actual_base) + " base");
		else {
			result *= actual_base;
			result += digit;
		}

	return result;
}

/**
 * Converts a decimal number to a given base.
 *
 * @param target_base The base to convert the decimal number to.
 * @param decimal The decimal representation of the input number.
 * @return a vector containing the digits of the number in the target base.
 */
std::vector <unsigned int> convert_number(int target_base, int decimal) {
	std::vector <unsigned int> result;

	while (decimal > 0) {
		result.insert(result.begin(), decimal % target_base);
		decimal /= target_base; // (decimal - decimal % target_base) / target_base
	}

	return result;
}

/**
 * Converts a number from one base to another base.
 *
 * @param actual_base The base of the input number.
 * @param digits A vector containing the digits of the input number.
 * @param target_base The base to convert the number to.
 * @return a vector containing the digits of the number in the target base.
 *
 * @throws std::invalid_argument if the input base is invalid.
 */
std::vector <unsigned int> all_your_base::convert(int actual_base, std::vector <unsigned int> digits, int target_base) {
	if (actual_base <= 1 || target_base <= 1)
		throw std::invalid_argument("Invalid base");

	int decimal = to_decimal(actual_base, digits);
	std::vector <unsigned int> result = convert_number(target_base, decimal);

	return result;
}
