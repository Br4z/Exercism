// URL: https://exercism.org/tracks/cpp/exercises/diamond DATE: 2024-02-04

#include "diamond.h"


/**
 * Generate a diamond shape with a specified letter at the widest point.
 *
 * @param letter The letter for the widest point of the diamond.
 * @return a vector of strings representing the diamond.
 */
std::vector <std::string> diamond::rows(char letter) {
	int n = letter - 'A';
	std::vector <std::string> diamond(2 * n + 1, std::string(2 * n + 1, ' '));

	for (int i = 0; i < n + 1; i++) {
		diamond[i][n + i] = 'A' + i;
		diamond[i][n - i] = 'A' + i;
		diamond[2 * n - i] = diamond[i];
	}

	return diamond;
}
