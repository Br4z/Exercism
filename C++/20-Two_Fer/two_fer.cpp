// URL: https://exercism.org/tracks/cpp/exercises/two-fer DATE: 2023-12-10

#include "two_fer.h"


/**
 * Returns a string in the format "One for {name}, one for me."
 *
 * @param name The name to be included in the string.
 * @return The resulting string.
 */
std::string two_fer::two_fer(std::string name) {
	return "One for " + name + ", one for me.";
}
