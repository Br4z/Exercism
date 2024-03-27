// URL: https://exercism.org/tracks/cpp/exercises/rail-fence-cipher DATE: 2024-08-28

#include "rail_fence_cipher.h"
#include <iostream>


/**
 * Encodes a given plain text using the Rail Fence Cipher algorithm.
 *
 * @param plain_text The plain text to be encoded.
 * @param number_rails The number of rails to be used in the cipher.
 * @return The encoded cipher text.
 */
std::string rail_fence_cipher::encode(const std::string &plain_text, int number_rails) {
	std::string output = "";
	int text_length = plain_text.length();
	char** rail = new char*[number_rails];
	int i, j;

	for (i = 0; i < number_rails; i++) {
		rail[i] = new char[text_length];
		for (j = 0; j < text_length; j++)
			rail[i][j] = '\n';
	}

	int row = 0, column = 0;
	bool dir_down = false;
	for (i = 0; i < text_length; i ++) {
		if (row == 0 || row == number_rails - 1)
			dir_down = !dir_down;

		rail[row][column++] = plain_text[i];

		dir_down ? row++ : row--;
	}

	for (i = 0; i < number_rails; i++)
		for (j = 0; j < text_length; j++) {
			char character = rail[i][j];

			if (character != '\n')
				output += character;
		}

	return output;
}

/**
 * Decodes a given cipher text using the Rail Fence Cipher algorithm.
 *
 * @param cipher_text The cipher text to be decoded.
 * @param number_rails The number of rails used in the Rail Fence Cipher.
 * @return The decoded plain text.
 */
std::string rail_fence_cipher::decode(const std::string &cipher_text, int number_rails) {
	std::string output = "";
	int cipher_text_length = cipher_text.length();
	char** rail = new char*[number_rails];
	int i, j;

	for (i = 0; i < number_rails; i++) {
		rail[i] = new char[cipher_text_length];
		for (j = 0; j < cipher_text_length; j++)
			rail[i][j] = '-';
	}

	int row = 0, column = 0;
	bool dir_down = false;
	for (i = 0; i < cipher_text_length; i ++) {
		if (row == 0 || row == number_rails - 1)
			dir_down = !dir_down;

		rail[row][column++] = '*';

		dir_down ? row++ : row--;
	}

	int character_position = 0;
	for (i = 0; i < number_rails; i++)
		for (j = 0; j < cipher_text_length; j++) {
			char character = rail[i][j];

			if (character == '*' && character_position < cipher_text_length)
				rail[i][j] = cipher_text[character_position++];
		}

	row = 0, column = 0;
	dir_down = false;
	for (i = 0; i < cipher_text_length; i ++) {
		if (row == 0 || row == number_rails - 1)
			dir_down = !dir_down;

		output += rail[row][column++];

		dir_down ? row++ : row--;
	}

	return output;
}
