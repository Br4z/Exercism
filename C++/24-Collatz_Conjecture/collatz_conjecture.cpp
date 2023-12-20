// URL: https://exercism.org/tracks/cpp/exercises/collatz-conjecture DATE: 2023-12-19

#include <stdexcept>

#include "collatz_conjecture.h"


int collatz_conjecture::steps(int n) {
	if (n <= 0) throw std::domain_error("Invalid input");


	int steps = 0;

	while (n != 1) {
		if (n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
		steps++;
	}

	return steps;
}
