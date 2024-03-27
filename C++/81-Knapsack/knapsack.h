// URL: https://exercism.org/tracks/cpp/exercises/knapsack DATE: 2024-02-16

#include <vector>

#ifndef KNAPSACK_H
#define KNAPSACK_H


namespace knapsack {
	struct Item {
		int weight;
		int value;
	};
	int maximum_value(int weight, std::vector <Item> items, int actual_item = 0);
}

#endif
