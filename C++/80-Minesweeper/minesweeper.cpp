// URL: https://exercism.org/tracks/cpp/exercises/minesweeper DATE: 2024-02-13

#include "minesweeper.h"


/**
 * Counts the number of mines adjacent to a given empty square.

 * @param board The Minesweeper board.
 * @param height The height of the Minesweeper board.
 * @param width The width of the Minesweeper board.
 * @param x The x-coordinate of the current square.
 * @param y The y-coordinate of the current square.
 * @return the number of mines adjacent to the current square.
 */
int minesweeper::count_mines(std::vector <std::string> &board, int &height, int &width, int &x, int &y) {
	/*
		(row - 1, col - 1) (row - 1, col) (row - 1, col + 1)
		(row, col - 1)            X       (row, col + 1)
		(row + 1, col - 1) (row + 1, col) (row + 1, col + 1)
	*/
	int result = 0;

	for (int i = std::max(0, y - 1); i <= std::min(height - 1, y + 1); i++)
		for (int j = std::max(0, x - 1); j <= std::min(width - 1, x + 1); j++)
			if (board[i][j] == '*')
				result++;

	return result;
}

/**
 * Adds mine counts to a Minesweeper board.
 *
 * @param board The Minesweeper board.
 * @return the Minesweeper board with mine counts.
 */
std::vector <std::string> minesweeper::annotate(std::vector <std::string> board) {
	int height = board.size();
	int width = height ?  board[0].length() : 0;

	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (board[i][j] == '*')
				continue;
			else {
				int mines = count_mines(board, height, width, j, i);
				board[i][j] = mines == 0 ? ' ' : mines + '0';
			}

	return board;
}
