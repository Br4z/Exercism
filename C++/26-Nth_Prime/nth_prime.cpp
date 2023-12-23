// URL: https://exercism.org/tracks/cpp/exercises/nth-prime DATE: 2023-12-21

#include <stdexcept>
#include <vector>

#include "nth_prime.h"


/**
 * Checks if a given number is divisible by any number in a vector.
 *
 * @param numbers The vector of numbers to check for divisibility.
 * @param number The number to check for divisibility.
 * @return True if the number is divisible by any number in the vector, false otherwise.
 */
bool is_divisible(std::vector <int> &numbers, int number) {
	for (int possible_divisor : numbers)
		if (number % possible_divisor == 0) return true;

	return false;
}

/**
 * Calculates the nth prime number.
 *
 * @param position The position of the prime number to calculate.
 * @return The nth prime number.
 */
int nth_prime::nth(int position) {
	std::vector <int> primes;

	for (int i = 2; ; i++) {
		if ((int) primes.size() == position) return primes.back();
		if (!is_divisible(primes, i)) primes.push_back(i);
	}
}
