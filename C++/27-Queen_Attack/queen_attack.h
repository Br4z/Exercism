// URL: https://exercism.org/tracks/cpp/exercises/queen-attack DATE: 2023-12-22

#include <iostream>

#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H


namespace queen_attack {
	class chess_board {
		private:
			const int board_size = 7;
			std::pair <int, int> white_position;
			std::pair <int, int> black_position;
		public:
			using position_type = std::pair <int, int>;

			chess_board(position_type white, position_type black);
			~chess_board();
			position_type white() const;
			position_type black() const;
			bool can_attack() const;
			std::string get_string_representation();
	};
}

#endif
