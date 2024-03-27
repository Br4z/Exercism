// URL: https://exercism.org/tracks/cpp/exercises/bob DATE: 2024-01-14

#include <regex>

#include "bob.h"

/**
 * Check if a sentence is a question.
 *
 * A sentence is considered a question if it ends with a question mark.
 *
 * @param sentence The input sentence to check.
 * @return true if the sentence is a question, false otherwise.
 */
bool is_question(std::string sentence) {
	std::regex regex(".*\\?\\s*");

	return std::regex_match(sentence, regex);
}

/**
 * Check if a sentence is yelling.
 *
 * A sentence is considered yelling if it contains all capital letters.
 *
 * @param sentence The input sentence to check.
 * @return true if the sentence is yelling, false otherwise.
 */
bool is_yelling(std::string sentence) {
	std::regex regex("[^a-z]*[A-Z]+[^a-z]*");

	return std::regex_match(sentence, regex);
}

/**
 * Check if a sentence is silence.
 *
 * A sentence is considered silence if it contains only whitespace characters.
 *
 * @param sentence The input sentence to check.
 * @return true if the sentence is silence, false otherwise.
 */
bool is_silence(std::string sentence) {
	std::regex regex("\\s*");

	return std::regex_match(sentence, regex);
}

/**
 * Determine Bob's response based on the input sentence.
 *
 * Bob responds differently to questions, yelling, silence, and other types of
 * sentences.
 *
 * @param sentence The input sentence to which Bob will respond.
 * @return Bob's response to the input sentence.
 */
std::string bob::hey(std::string sentence) {
	bool question = is_question(sentence);
	bool yelling = is_yelling(sentence);
	bool silence = is_silence(sentence);

	if (question)
		return yelling ? "Calm down, I know what I'm doing!" : "Sure.";
	else if (yelling)
		return "Whoa, chill out!";
	else if (silence)
		return "Fine. Be that way!";
	else
		return "Whatever.";
}
