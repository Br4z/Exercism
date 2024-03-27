// URL: https://exercism.org/tracks/cpp/exercises/crypto-square DATE: 2024-01-18

#include <algorithm>
#include <cmath>

#include "crypto_square.h"


crypto_square::cipher::cipher(std::string text) : text(text) {
	normalized_text = normalize_plain_text();
	int normalized_text_length = normalized_text.length();

	c = ceil(sqrt(normalized_text_length));
	r = ceil(static_cast <double> (normalized_text_length) / c);

	std::vector <std::string> text_segments = plain_text_segments();

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			ciphered_text += i >= (int) text_segments[j].length() ? ' ' : text_segments[j][i];
}

/**
 * Normalize the plaintext by removing spaces and punctuation, and
 * converting to lowercase.
 *
 * @return the normalized plaintext.
 */
std::string crypto_square::cipher::normalize_plain_text() {
	std::string result;

	for (char& character : text)
		if (isalpha(character) || isalnum(character))
			result += tolower(character);

	return result;
}

/**
 * Split the normalized plaintext into segments, each of length "c".
 *
 * @return a vector of strings, each representing a segment.
 */
std::vector <std::string> crypto_square::cipher::plain_text_segments() {
	std::vector <std::string> text_segments;

	for (int i = 0; i < r; i++)
		text_segments.push_back(normalized_text.substr(i * c, c));

	return text_segments;
}

/**
 * Get the ciphered text.
 *
 * @return the ciphered text without spaces.
 */
std::string crypto_square::cipher::cipher_text() {
	std::string ciphered_text_copy = ciphered_text;

	ciphered_text_copy.erase(std::remove_if(ciphered_text_copy.begin(), ciphered_text_copy.end(),
		::isspace), ciphered_text_copy.end());

	return ciphered_text_copy;
}

/**
 * Get the normalized ciphered text with spaces between segments.
 *
 * @return the normalized ciphered text.
 */
std::string crypto_square::cipher::normalized_cipher_text() {
	std::string result;

	for (int i = 0; i < c; i++) {
		result += ciphered_text.substr(i * r, r);

		if (i != c - 1)
			result += ' ';
	}

	return result;
}
