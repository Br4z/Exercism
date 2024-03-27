// URL: https://exercism.org/tracks/cpp/exercises/trinary DATE: 2024-01-06

#include <cmath>

#include "trinary.h"


/**
 * Converts a trinary number to its decimal representation.
 *
 * @param trinary_number The trinary number to convert.
 * @return the decimal representation of the trinary number.
 */
int trinary::to_decimal(std::string trinary_number) {
	int result = 0;
	int trinary_length = trinary_number.length() - 1;

	for (int i = trinary_length; i >= 0; i--) {
		int number = trinary_number[trinary_length - i] - '0';

		if (2 < number || number < 0)
			return 0;
		else
			result += number * pow(3, i);
	}

	return result;

/* 	int sum = 0;

	for (char digit : trinary_number) {
		if (digit > '2' || digit < '0') return 0;
		sum = 3 * sum + (digit - '0');
	}

	return sum; */
}
