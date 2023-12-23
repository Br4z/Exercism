// URL: https://exercism.org/tracks/cpp/exercises/hamming DATE: 2023-12-16

#include <stdexcept>

#include "hamming.h"


/**
 * Calculates the Hamming distance between two strings.
 * The strings must be of equal length.
 *
 * @param a The first string.
 * @param b The second string.
 * @return The Hamming distance between the two strings.
 * @throws std::domain_error if the strings are not of equal length.
 */
int hamming::compute(std::string a, std::string b) {
	if (a.length() != b.length()) {
		throw std::domain_error("Strings must be of equal length");
	}

	int hamming_distance = 0;

	for (long unsigned int i = 0; i < (int) a.length(); i++)
		hamming_distance += a[i] != b[i];

	return hamming_distance;
}
