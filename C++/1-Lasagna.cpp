// URL: https://exercism.org/tracks/cpp/exercises/lasagna DATE: 2023-12-07

/* --------------------------------- TASK 1 --------------------------------- */

/**
 * Returns the oven time for cooking lasagna.
 *
 * @return The oven time in minutes.
 */
int ovenTime() {
	return 40;
}

/* --------------------------------- TASK 2 --------------------------------- */

/**
 * Calculates the remaining time in the oven for a lasagna based on the actual
 * minutes it has been in the oven.
 *
 * @param actualMinutesInOven The actual minutes the lasagna has been in the oven.
 * @return The remaining time in the oven for the lasagna.
 */
int remainingOvenTime(int actualMinutesInOven) {
	return ovenTime() - actualMinutesInOven;
}

/* --------------------------------- TASK 3 --------------------------------- */

/**
 * Calculates the preparation time for making lasagna based on the number of
 * layers. Each layer takes 2 minutes to prepare.
 *
 * @param numberOfLayers The number of layers in the lasagna.
 * @return The total preparation time in minutes.
 */
int preparationTime(int numberOfLayers) {
	return numberOfLayers * 2;
}

/* --------------------------------- TASK 4 --------------------------------- */

/**
 * Calculates the total elapsed time for cooking lasagna.
 *
 * @param numberOfLayers The number of layers of lasagna.
 * @param actualMinutesInOven The actual minutes the lasagna has been in the oven.
 * @return The total elapsed time for cooking lasagna.
 */
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
	return actualMinutesInOven + preparationTime(numberOfLayers);
}
