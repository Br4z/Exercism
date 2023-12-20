// URL: https://exercism.org/tracks/cpp/exercises/difference-of-squares DATE: 2023-12-20

#include <stdexcept>

#include "difference_of_squares.h"


int difference_of_squares::square_of_sum(int n) {
	if (n < 0) throw std::domain_error("Invalid input");

	int sum = 0;

	for (int i = 0; i <= n; i++) sum += i;

	// int sum = (n * (n + 1)) / 2;

	return sum * sum;
}

int difference_of_squares::sum_of_squares(int n) {
	if (n < 0) throw std::domain_error("Invalid input");

	int sum = 0;

	for (int i = 0; i <= n; i++) sum += i * i;

	// int sum = (n * (n + 1) * (2 * n + 1)) / 6;

	return sum;
}

int difference_of_squares::difference(int n) {
	return square_of_sum(n) - sum_of_squares(n);
}
