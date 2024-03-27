// URL: https://exercism.org/tracks/cpp/exercises/sum-of-multiples DATE: 2023-12-31

#include "sum_of_multiples.h"


/**
 * Calculates the energy points that get awarded to players when they
 * complete a level.
 *
 * @param magic_items The base value of each magical item collected
 * by the player during that level.
 * @param level The level (number) that the player completed.
 * @return the energy points that the player got.
 */
int sum_of_multiples::to(std::vector <int> magic_items, int level) {
	int energy_points = 0;

	for (int i = 1; i < level; i++)
		for (int magic_item : magic_items)
			if (i % magic_item == 0) {
				energy_points += i;
				break;
			}

	return energy_points;
}
