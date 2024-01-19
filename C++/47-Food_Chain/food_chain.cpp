// URL: https://exercism.org/tracks/cpp/exercises/food-chain DATE: 2024-01-11

#include <vector>

#include  "food_chain.h"


std::vector <std::string> animals = {
	"fly",
	"spider",
	"bird",
	"cat",
	"dog",
	"goat",
	"cow",
	"horse"
};

std::vector <std::string> animals_intros = {
	"",
	"It wriggled and jiggled and tickled inside her.",
	"How absurd to swallow a bird!",
	"Imagine that, to swallow a cat!",
	"What a hog, to swallow a dog!",
	"Just opened her throat and swallowed a goat!",
	"I don't know how she swallowed a cow!",
	"She's dead, of course!"
};

/**
 * Generate the lyrics for a specific verse in the "I Know an Old Lady Who Swallowed a Fly"
 * song.
 *
 * @param verse_number The number of the verse to generate (1 to 8).
 * @return The lyrics for the specified verse.
 */
std::string food_chain::verse(int verse_number) {
	int animal_index = verse_number - 1;
	std::string swallowed = animals[animal_index];

	std::string verse =
		"I know an old lady who swallowed a " + animals[animal_index] + '.' + '\n' +
		animals_intros[animal_index];

	if (swallowed != "fly")
		verse += '\n';

	if (swallowed == "horse")
		return verse;
	else if (verse_number >= 2) {
		for (int i = animal_index; i > 0; i--) {
			swallowed = animals[i];
			std::string previous_swallowed = animals[i - 1];

			verse += "She swallowed the " + swallowed + " to catch the " + previous_swallowed;

			if (previous_swallowed == "spider")
				verse += " that wriggled and jiggled and tickled inside her";

			verse += ".\n";
		}
	}

	verse += "I don't know why she swallowed the fly. Perhaps she'll die.\n";

	return verse;
}

/**
 * Generate the lyrics for a range of verses in the "I Know an Old Lady Who Swallowed a Fly"
 * song.
 *
 * @param start The starting verse number.
 * @param end The ending verse number.
 * @return The lyrics for the specified range of verses.
 */
std::string food_chain::verses(int start, int end) {
	std::string verses;

	for (int i = start; i <= end; i++)
		verses += verse(i) + '\n';

	return verses;
}

/**
 * Generate the complete lyrics for the "I Know an Old Lady Who Swallowed a Fly"
 * song.
 *
 * @return The complete lyrics of the song.
 */
std::string food_chain::sing() {
	return verses(1, 8);
}
