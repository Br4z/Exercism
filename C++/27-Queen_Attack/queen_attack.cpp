// URL: https://exercism.org/tracks/cpp/exercises/queen-attack DATE: 2023-12-22

#include <cmath>
#include <stdexcept>

#include "queen_attack.h"


queen_attack::chess_board::chess_board(position_type white, position_type black) :
	white_position(white), black_position(black) {

	if (white == black)
		throw std::domain_error("Queen positions must be distinct!");

	if (white.first > board_size || white.first < 0 ||
		white.second > board_size || white.second < 0 ||
		black.first > board_size || black.first < 0 ||
		black.second > board_size || black.second < 0)
		throw std::domain_error("Out of edges");
}

queen_attack::chess_board::~chess_board() {

}

/**
 * Returns the position of the white queen on the chess board.
 *
 * @return the position of the white queen.
 */
queen_attack::chess_board::position_type queen_attack::chess_board::white() const {
	return white_position;
}

/**
 * Returns the position of the black queen on the chess board.
 *
 * @return the position of the black queen.
 */
queen_attack::chess_board::position_type queen_attack::chess_board::black() const {
	return black_position;
}

/**
 * Determines whether the white queen can attack the black queen on a chess board.
 *
 * @return true if the white queen can attack the black queen, false otherwise.
 */
bool queen_attack::chess_board::can_attack() const {
	bool row = white_position.first == black_position.first;
	bool column = white_position.second == black_position.second;
	bool diagonal = std::abs(white_position.first - black_position.first) == std::abs(white_position.second - black_position.second);

	return row || column || diagonal;
}

/**
 * Returns a string representation of the chess board.
 *
 * The string representation includes the positions of the white and black queens.
 * The board is represented as a grid of size 8x8, with each cell containing either
 * an empty space (_), the white queen (W), or the black queen (B).
 *
 * @return the string representation of the chess board.
 */
std::string queen_attack::chess_board::get_string_representation() {
	std::string board;

	board.append("  0 1 2 3 4 5 6 7\n");

	for (int i = 0; i < board_size; i++) {
		std::string line = std::to_string(i) + " _ _ _ _ _ _ _ _\n";

		if (i == white_position.first)
			line[white_position.second * 2] = 'W';
		else if (i == black_position.first)
			line[black_position.second * 2] = 'B';

		board.append(line);
	}

	return board;
}
