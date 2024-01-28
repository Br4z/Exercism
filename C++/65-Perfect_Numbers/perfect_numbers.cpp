// URL: https://exercism.org/tracks/cpp/exercises/perfect-numbers DATE: 2024-01-28

#include <stdexcept>

#include "perfect_numbers.h"


/**
 * Classify a positive integer as perfect, abundant, or deficient.
 *
 * @param number The positive integer to be classified.
 * @return The classification of the number (perfect, abundant, or deficient).
 * @throws std::domain_error if the input number is not a positive integer.
 */
perfect_numbers::Number_Class perfect_numbers::classify(int number) {
	if (number < 1)
		throw std::domain_error("Invalid number");

	int sum = 0;

	for (int i = 1; i < number / 2; i++)
		if (number % i == 0)
			sum += i;

	if (number == sum)
		return perfect_numbers::Number_Class::perfect;
	else if (number < sum)
		return perfect_numbers::Number_Class::abundant;
	else
		return perfect_numbers::Number_Class::deficient;
}
