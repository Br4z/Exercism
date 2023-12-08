// URL: https://exercism.org/tracks/cpp/exercises/lasagna DATE: 2023-12-07

/* --------------------------------- TASK 1 --------------------------------- */

// ovenTime returns the amount in minutes that the lasagna should stay in the
// oven.
int ovenTime() {
	return 40;
}

/* --------------------------------- TASK 2 --------------------------------- */

// remainingOvenTime returns the remaining minutes based on the actual minutes
// already in the oven.

int remainingOvenTime(int actualMinutesInOven) {
	return ovenTime() - actualMinutesInOven;
}

/* --------------------------------- TASK 3 --------------------------------- */

// preparationTime returns an estimate of the preparation time based on the
// number of layers and the necessary time per layer.
int preparationTime(int numberOfLayers) {
	return numberOfLayers * 2;
}

/* --------------------------------- TASK 4 --------------------------------- */

// elapsedTime calculates the total time spent to create and bake the lasagna so
// far.
int elapsedTime(int numberOfLayers, int actualMinutesInOven) {
	return actualMinutesInOven + preparationTime(numberOfLayers);
}
