// URL: https://exercism.org/tracks/cpp/exercises/largest-series-product DATE: 2024-02-02

#include <stdexcept>
#include <vector>

#include "largest_series_product.h"


/**
 * Find the maximum element in a vector.
 *
 * @param vector The input vector.
 * @return The maximum element in the vector.
 *
 * @throws std::domain_error if the vector is empty.
*/
template <typename T>
T max(std::vector <T> vector) {
	if (vector.empty())
		throw std::domain_error("The vector is empty");

	T max = vector[0];

	for (int i = 1; i < (int) vector.size(); i++) {
		T element = vector[i];

		if (element > max)
			max = element;
	}

	return max;
}

/**
 * Check if the input string is valid (contains only digits).
 *
 * @param input The input string.
 * @return true if the input is valid, false otherwise.
*/
bool is_valid_input(std::string input) {
	bool result = true;

	for (const char character : input)
		if (!isdigit(character)) {
			result = false;
			break;
		}

	return result;
}

/**
 * Calculate the product of a given series.
 *
 * @param series The series.
 * @return The product of the series.
*/
int series_product(std::string series) {
	int result = 1;

	for (const char number : series)
		result *= number - '0';

	return result;
}

/**
 * Calculate the products of a given series.
 *
 * @param series The vector of series.
 * @return A vector containing the products of the series.
*/
std::vector <int> series_products(std::vector <std::string> series_vector) {
	std::vector <int> result;

	for (const auto &series : series_vector)
		result.push_back(series_product(series));

	return result;
}

/**
 * Slice a given string into contiguous substrings of a specified length.
 *
 * @param string The input string to be sliced.
 * @param slices_length The desired length for each substring.
 * @return A vector containing all the sliced substrings.
 *
 * @throws std::domain_error if the slice length is invalid or if the input string is empty.
*/
std::vector <std::string> slice(std::string string, int slices_length) {
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

/**
 * Find the largest series product within a given sequence of digits.
 *
 * @param input The sequence of digits to analyze.
 * @param span The length of each series.
 * @return The largest series product.
 *
 * @throws std::domain_error if the input is invalid.
 */
int largest_series_product::largest_product(std::string input, int span) {
	if (!is_valid_input(input))
		throw std::domain_error("Invalid input");

	std::vector <std::string> series_vector = slice(input, span);
	std::vector <int> products = series_products(series_vector);

	return max(products);
}
