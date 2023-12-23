// URL: https://exercism.org/tracks/cpp/exercises/grains DATE: 2023-12-09

#include <cmath>

#include "grains.h"


/**
 * Calculates the number of grains on a specific square of a chessboard.
 *
 * @param square_number The number of the square on the chessboard.
 * @return The number of grains on the specified square.
 */
unsigned long long grains::square(int square_number) {
	return 1ULL << (square_number - 1);
}

/**
 * Calculates the total number of grains on a chessboard.
 *
 * @return The total number of grains on the chessboard.
 */
unsigned long long grains::total() {
	unsigned long long total = 0;

	for (int i = 1; i <= 64; i++)
		total += square(i);

	return total; // (1ULL << 63) * 2 - 1;
}
