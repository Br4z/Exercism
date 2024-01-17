// URL: https://exercism.org/tracks/cpp/exercises/roman_numerals DATE: 2024-01-13

#include <stdexcept>

#include "roman_numerals.h"


/**
 * Converts a decimal number to a Roman numeral representation.
 *
 * @param decimal_number The decimal number to convert.
 * @return The Roman numeral representation of the input decimal number.
 * @throws std::domain_error if the input decimal number is greater than 3000.
 */
std::string number_to_roman(int decimal_number) {
	if (decimal_number > 3000)
		throw std::domain_error("The number is too large");

	switch (decimal_number) {
		/* ---------------------------------- UNITS --------------------------------- */

		case 0: return "";
		case 1: return "I";
		case 2: return "II";
		case 3: return "III";
		case 4: return "IV";
		case 5: return "V";
		case 6: return "VI";
		case 7: return "VII";
		case 8: return "VIII";
		case 9: return "IX";

		/* ---------------------------------- TENS ---------------------------------- */

		case 10: return "X";
		case 20: return "XX";
		case 30: return "XXX";
		case 40: return "XL";
		case 50: return "L";
		case 60: return "LX";
		case 70: return "LXX";
		case 80: return "LXXX";
		case 90: return "XC";

		/* -------------------------------- HUNDREDS -------------------------------- */

		case 100: return "C";
		case 200: return "CC";
		case 300: return "CCC";
		case 400: return "CD";
		case 500: return "D";
		case 600: return "DC";
		case 700: return "DCC";
		case 800: return "DCCC";
		case 900: return "CM";

		/* -------------------------------- Thousands ------------------------------- */

		case 1000: return "M";
		case 2000: return "MM";
		case 3000: return "MMM";


		default: return "";
	}
}

/**
 * Converts a decimal number to a Roman numeral representation.
 *
 * @param decimal_number The decimal number to convert.
 * @return The Roman numeral representation of the decimal number.
 */
std::string roman_numerals::convert(int decimal_number) {
	std::string conversion;

	int thousands = decimal_number / 1000;
	int hundreds = decimal_number / 100 - thousands * 10;
	int tens = decimal_number / 10 - thousands * 100 - hundreds * 10;
	int units = decimal_number - thousands * 1000 - hundreds * 100 - tens * 10;

	conversion += number_to_roman(thousands * 1000);
	conversion += number_to_roman(hundreds * 100);
	conversion += number_to_roman(tens * 10);
	conversion += number_to_roman(units);

	return conversion;
}
