// URL: https://exercism.org/tracks/cpp/exercises/armstrong-numbersarmstrong_numbers DATE: 2024-01-25

#include <cmath>

#include "armstrong_numbers.h"


/**
 * Determine whether a given number is an Armstrong number.
 *
 * @param number The input number to be checked.
 * @return True if the number is an Armstrong number, false otherwise.
 */
bool armstrong_numbers::is_armstrong_number(int number) {
	int number_length = log10(number) + 1; int n = number;
	int sum = 0;

	while (n != 0) {
		sum += pow(n % 10, number_length);
		n /= 10;
	}

	return sum == number;
}
