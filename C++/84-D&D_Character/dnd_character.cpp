// URL: https://exercism.org/tracks/cpp/exercises/dnd-character DATE: 2024-02-18

#include <cstdlib>

#include "dnd_character.h"


dnd_character::Character::Character() {

}

/**
 * Calculates the ability modifier based on the given constitution.
 * @param constitution The constitution score.
 * @return The ability modifier.
 */
int dnd_character::modifier(int constitution) {
	int result = constitution - 10;

	if (result < 0)
		result -= 1;

	return result / 2;
}

/**
 * Generates a random ability score using four six-sided dice.
 * @return The randomly generated ability score.
 */
int dnd_character::ability() {
	int min = -1;
	int rolls[4];

	for (int i = 0; i < 4; i++) {
		int random = rand() % 6 + 1;

		rolls[i] = random;

		if (random < min)
			min = random;
	}

	int result = -1 * min;

	for (int i = 0; i < 3; i++)
		result += rolls[i];

	return result;
}
