// URL: https://exercism.org/tracks/cpp/exercises/binary-search DATE: 2023-12-28

#include <stdexcept>

#include "binary_search.h"


/**
 * Finds the index of the target value in the given vector of numbers using binary search.
 *
 * @param numbers The vector of numbers to search in.
 * @param target The target value to find.
 * @return The index of the target value if found, otherwise throws an exception.
 * @throws std::domain_error If the array is empty, the target is not
 * in the array or the array is not sorted correctly.
 */
int binary_search::find(std::vector <int> numbers, int target) {
	if (numbers.empty())
		throw std::domain_error("The array is empty");

	int left = 0; int right = numbers.size() - 1;

	while (left <= right) {
		int middle = (left + right) / 2; // left + (left - right) / 2

		if (target == numbers[middle])
			return middle;
		else if (target < numbers[middle])
			right = middle - 1;
		else
			left = middle + 1;
	}

	throw std::domain_error("The target is not in the array or is not sorted correctly");
}
