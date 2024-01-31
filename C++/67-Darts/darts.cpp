// URL: https://exercism.org/tracks/cpp/exercises/darts DATE: 2024-01-29

#include <cmath>

#include "darts.h"


/**
 * Calculate the earned points based on the coordinates of the dart landing point.
 *
 * @param x The x-coordinate of the dart landing point.
 * @param y The y-coordinate of the dart landing point.
 * @return The earned points for the dart landing at the given coordinates.
 */
int darts::score(float x, float y) {
	float distance = sqrt(pow(x, 2) + pow(y, 2));

	if (distance > 10)
		return 0;
	else if (distance > 5)
		return 1;
	else if (distance > 1)
		return 5;
	else
		return 10;
}
