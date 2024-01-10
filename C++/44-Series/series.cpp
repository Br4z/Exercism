// URL: https://exercism.org/tracks/cpp/exercises/series DATE: 2024-01-07

#include <stdexcept>

#include "series.h"

/**
 * Slice a given string into contiguous substrings of a specified length.
 *
 * @param string The input string to be sliced.
 * @param slices_length The desired length for each substring.
 * @return A vector containing all the sliced substrings.
 *
 * @throws std::domain_error if the slice length is invalid or if the input string is empty.
 */
std::vector <std::string> series::slice(std::string string, int slices_length) {
	std::vector <std::string> slices;
	int string_length = string.length();

	if (slices_length > string_length || slices_length <= 0)
		throw std::domain_error("slice length is invalid");

	for (int i = 0; string_length - i >= slices_length; i++) {
		std::string slice = string.substr(i, slices_length);
		slices.push_back(slice);
	}

	return slices;
}
