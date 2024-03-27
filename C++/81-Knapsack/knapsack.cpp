// URL: https://exercism.org/tracks/cpp/exercises/knapsack DATE: 2024-02-16

#include "knapsack.h"


/**
 * Returns the maximum of two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return the greater of the two integers.
 */
int max(int a, int b) {
	return a > b ? a : b;
}

/**
 * @brief Computes the maximum value that can be obtained by filling the knapsack.
 *
 * @param weight The remaining weight capacity of the knapsack.
 * @param items A vector of items, each represented by weight and value.
 * @param actual_item The index of the current item being considered.
 * @return the maximum value achievable by filling the knapsack with the given items.
 */
int knapsack::maximum_value(int weight, std::vector <Item> items, int actual_item) {
	int items_size = items.size();

	if (weight == 0 || actual_item == items_size)
		return 0;

	if (items[actual_item].weight > weight)
		return maximum_value(weight, items, actual_item + 1);
	else {
		return max(items[actual_item].value + maximum_value(weight - items[actual_item].weight, items, actual_item + 1),
			maximum_value(weight, items, actual_item + 1));
	}
}
