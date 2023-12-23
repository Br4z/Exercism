// URL: https://exercism.org/tracks/cpp/exercises/reverse-string DATE: 2023-12-08

#include <math.h>
#include <string>


namespace reverse_string {
	/**
	 * Reverses a given string.
	 *
	 * @param string The string to be reversed.
	 * @return The reversed string.
	 */
	std::string reverse_string(std::string string) {
		int string_length = string.length();

		for (int i = 0; i < floor(string_length / 2); i++) {
			char temp = string[i];

			string[i] = string[string_length - 1 - i];
			string[string_length - 1 - i] = temp;
		}

		return string;
	}
}
