// URL: https://exercism.org/tracks/cpp/exercises/secret-handshake DATE: 2023-12-25

#include "secret_handshake.h"


/**
 * Reverses a given string vector.
 *
 * @param string The string vector to be reversed.
 * @return the reversed string vector.
 */
void reverse_string_vector(std::vector <std::string> &vector) {
	int vector_size = vector.size();

	for (int i = 0; i < vector_size / 2; i++) {
		std::string temp = vector[i];

		vector[i] = vector[(vector_size - 1) - i];
		vector[(vector_size - 1) - i] = temp;
	}
}

/**
 * Converts a number between 1 and 31 to a sequence of actions in
 * the secret handshake.
 *
 * @param int The person's number.
 * @return the secret handshake for the given number.
 */
std::vector <std::string> secret_handshake::commands(int n) {
	std::vector <std::string> commands; int commands_number = 4;

	const std::string possible_commands[] = {
		"wink", // 00001 = 1
		"double blink", // 00010 = 2
		"close your eyes", // 00100 = 4
		"jump", // 01000 = 8
	};

	for (int i = 0; i < commands_number; i++) {
		int result = 1 << i & n;

		if (result)
			commands.push_back(possible_commands[i]);
	}

	if (1 << (commands_number + 1) & n) // Last command (10000) Reverse the order of the operations
		reverse_string_vector(commands);

	return commands;
}
