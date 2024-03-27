// URL: https://exercism.org/tracks/cpp/exercises/minesweeper DATE: 2024-02-13

#include <string>
#include <vector>

#ifndef MINESWEEPER_H
#define MINESWEEPER_H


namespace minesweeper {
	int count_mines(std::vector <std::string> &board, int &height, int &width, int &x, int &y);
	std::vector <std::string> annotate(std::vector <std::string> board);
}

#endif
