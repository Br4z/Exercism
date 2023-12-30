// URL: https://exercism.org/tracks/cpp/exercises/difference-of-squares DATE: 2023-12-20

#include <stdexcept>

#include "difference_of_squares.h"


/**
 * Calculates the square of the sum of the first n natural numbers.
 * (1 + 2 + ... + n)^2
 *
 * @param n The number of natural numbers to consider.
 * @return The square of the sum of the first n natural numbers.
 * @throws std::domain_error if n is negative.
 */
int difference_of_squares::square_of_sum(int n) {
	if (n < 0)
		throw std::domain_error("Invalid input");

	int sum = 0;

	for (int i = 0; i <= n; i++)
		sum += i;

	// int sum = (n * (n + 1)) / 2;

	return sum * sum;
}

/**
 * Calculates the sum of squares up to a given number.
 * 1^2 + 2^2 + ... + n^2
 *
 * @param n The upper limit of the range.
 * @return The sum of squares up to the given number.
 * @throws std::domain_error if the input is negative.
 */
int difference_of_squares::sum_of_squares(int n) {
	if (n < 0)
		throw std::domain_error("Invalid input");

	int sum = 0;

	for (int i = 0; i <= n; i++)
		sum += i * i;

	// int sum = (n * (n + 1) * (2 * n + 1)) / 6;

	return sum;
}

/**
 * Calculates the difference between the square of the sum and the
 * sum of squares of the first n natural numbers.
 *
 * @param n The number of natural numbers to consider.
 * @return The difference between the square of the sum and the sum of squares.
 */
int difference_of_squares::difference(int n) {
	return square_of_sum(n) - sum_of_squares(n);
}
