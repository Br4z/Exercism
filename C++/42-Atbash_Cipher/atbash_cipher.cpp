// URL: https://exercism.org/tracks/cpp/exercises/atbash-cipher DATE: 2024-01-06

#include <cctype>

#include "atbash_cipher.h"


/**
 * Encodes a character using the Atbash cipher.
 * If the character is a digit, it is returned as is.
 * If the character is a letter, it is converted to its Atbash cipher equivalent.
 *
 * @param character The character to be encoded.
 * @return the encoded character.
 */
char encode_character(char character) {
	return std::isdigit(character) ? character : (char) ('z' - (std::tolower(character) % 'a'));
}

/**
 * Encodes a message using the Atbash cipher.
 *
 * @param message The message to be encoded.
 * @return the encoded message with spaces inserted after every 5 characters.
 */
std::string atbash_cipher::encode(std::string message) {
	int message_length = message.length();
	std::string encode_message;
	int character_count = 0;

	for (int i = 0; i < message_length; i++)
		if (std::isalnum(message[i])) {
			if (character_count == 5) {
				encode_message += ' ';
				character_count = 0;
			}
			encode_message += encode_character(message[i]);
			character_count++;
		}

	return encode_message;
}

/**
 * Decodes a given message that was encoded using the Atbash cipher.
 *
 * @param message The message to be decoded.
 * @return the decoded message.
 */
std::string atbash_cipher::decode(std::string message) {
	std::string decode_with_spaces = encode(message);
	std::string decode_without_spaces;

	for (int i = 0; i < (int) decode_with_spaces.length(); i++)
		if (decode_with_spaces[i] != ' ')
			decode_without_spaces += decode_with_spaces[i];

	return decode_without_spaces;
}
