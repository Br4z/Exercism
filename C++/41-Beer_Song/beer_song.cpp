// URL: https://exercism.org/tracks/cpp/exercises/beer-song DATE: 2024-01-05

#include "beer_song.h"


/**
 * Recite a verse of the 99 Bottles of Beer on the Wall song.
 *
 * @param verse The verse number to recite. It should be between 0 and 99.
 * @return the verse number "verse" of the song.
 */
std::string beer_song::verse(int verse) {
	std::string verse_content;

	if (verse) {
		std::string current_bottles = std::to_string(verse);
		std::string remaining_bottles = (verse - 1) ? std::to_string(verse - 1) : "no more";
		std::string current_bottles_grammatical_number = std::string(" bottle") + (current_bottles != "1" ? "s" : "");
		std::string bottles_possessive = (current_bottles != "1") ? "one" : "it";
		std::string remaining_bottles_grammatical_number = std::string(" bottle") + (remaining_bottles != "1" ? "s" : "");

		verse_content = current_bottles + current_bottles_grammatical_number + " of beer on the wall, " +
			current_bottles + current_bottles_grammatical_number + " of beer.\n"
			"Take " + bottles_possessive + " down and pass it around, "
			+ remaining_bottles + remaining_bottles_grammatical_number + " of beer on the wall.\n";
	} else
		verse_content = "No more bottles of beer on the wall, no more bottles of beer.\n"
			"Go to the store and buy some more, 99 bottles of beer on the wall.\n";

	return verse_content;
}

/**
 * Recite the lyrics to that beloved classic, that field-trip favorite:
 * 99 Bottles of Beer on the Wall.
 *
 * @param start The starting verse number. It should be between 0 and 99.
 * @param end The ending verse number. It should be between 0 and 99 and
 * less than the start verse.
 * @return the lyrics starting from the "start" verse to the "end" verse.
 */
std::string beer_song::sing(int start, int end) {
	std::string sing_content;

	for (int i = start; i >= end; i--) {
		sing_content += verse(i);

		if (i != end)
			sing_content += '\n';
	}

	return sing_content;
}
