// URL: https://exercism.org/tracks/cpp/exercises/roman_numerals DATE: 2024-01-15

#include <stdexcept>

#include "roman_numerals.h"


const std::string romans[13] = {
	"M", "CM", "D", "CD",
	"C", "XC", "L", "XL",
	"X", "IX", "V", "IV",
	"I"
};

const int decimals[13] = {
	1000, 900, 500, 400,
	 100,  90,  50,  40,
	  10,   9,   5,   4,
	   1
};

/**
 * Converts a decimal number to a Roman numeral representation.
 *
 * @param decimal_number The decimal number to convert.
 * @return The Roman numeral representation of the decimal number.
 */
std::string roman_numerals::convert(int decimal_number) {
	std::string conversion;

	for (int i = 0; i < 13; i++) {
		int quotient = decimal_number / decimals[i];
		decimal_number %= decimals[i];

		for (int j = 0; j < quotient; j++)
			conversion += romans[i];
	}

	return conversion;
}
