// URL: https://exercism.org/tracks/cpp/exercises/matching-brackets DATE: 2024-01-20

#include <stdexcept>
#include <stack>

#include "matching_brackets.h"


/**
 * Check if the given character is an opening character.
 *
 * @param character The character to check.
 * @return true if the character is an opening bracket, brace,
 * or parenthesis, false otherwise.
 */
bool is_opening_character(char &character) {
	switch (character)	{
		case '[':
		case '{':
		case '(':
			return true;
		default:
			return false;
	}
}

/**
 * Check if the given character is a closing character.
 *
 * @param character The character to check.
 * @return true if the character is a closing bracket, brace,
 * or parenthesis, false otherwise.
 */
bool is_closing_character(char &character) {
	switch (character) {
		case ']':
		case '}':
		case ')':
			return true;
		default:
			return false;
	}
}

/**
 * Get the corresponding closing character for a given opening character.
 *
 * @param opening_character The opening character to find the closing
 * character for.
 * @return the corresponding closing character.
 * @throws std::domain_error if the input character is not a valid
 * opening character.
 */
char opening_character_pair(char &opening_character) {
	switch (opening_character) {
		case '[':
			return ']';
			break;
		case '{':
			return '}';
			break;
		case '(':
			return ')';
			break;
	}

	throw std::domain_error("Invalid opening character");
}

/**
 * Check if the brackets in the given string are matched and nested correctly.
 *
 * This function verifies that any and all pairs of brackets (round, square, and curly) in
 * the given string are correctly matched and nested.
 *
 * @param text The input string containing brackets and other characters.
 * @return true if all brackets are matched and nested correctly, false otherwise.
 */
bool matching_brackets::check(std::string text) {
	std::stack <char> stack;

	for (char& character : text)
		if (is_opening_character(character))
			stack.push(opening_character_pair(character));
		else if (is_closing_character(character))
			if (stack.empty() || stack.top() != character)
				return false;
			else
				stack.pop();

	return stack.empty();
}
