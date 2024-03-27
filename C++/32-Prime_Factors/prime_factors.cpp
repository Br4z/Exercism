// URL: https://exercism.org/tracks/cpp/exercises/prime-factors DATE: 2023-12-27

#include "prime_factors.h"


/**
 * Calculates the prime factors of a given number.
 *
 * @param n The number for which to calculate the prime factors.
 * @return a vector containing the prime factors of the given number.
 */
std::vector <int> prime_factors::of(int n) {
	std::vector <int> prime_factors;

	for (int i = 2; n != 1; i++)
		while (n % i == 0) {
			prime_factors.push_back(i);
			n /= i;
		}

	return prime_factors;
}
