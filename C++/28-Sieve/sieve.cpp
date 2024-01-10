// URL: https://exercism.org/tracks/cpp/exercises/sieve DATE: 2023-12-23

#include <iostream>
#include <numeric>

#include "sieve.h"


/**
 * Finds the prime numbers between 2 and the number "n".
 *
 * @param n The upper limit to search for prime numbers.
 * @return The vector containing the prime numbers from 2 to "n" number.
 */
std::vector <int> sieve::primes(int n) {
	std::vector <int> numbers(n - 1);
	std::iota(numbers.begin(), numbers.end(), 2);

	for (int i = 0; i < (int) numbers.size(); i++)
		for (int j = i + 1; j < (int) numbers.size(); j++)
			if (numbers[j] % numbers[i] == 0)
				numbers.erase(numbers.begin() + j);

	return numbers;
}
