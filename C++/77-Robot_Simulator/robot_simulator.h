// URL: https://exercism.org/tracks/cpp/exercises/robot-simulator DATE: 2024-02-08

#include <utility>
#include <string>

#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H


using position_type = std::pair <int, int>;

namespace robot_simulator {
	enum class Bearing {
		NORTH,
		EAST,
		SOUTH,
		WEST,
	};

	class Robot {
		private:
			position_type position_;
			Bearing bearing_;
		public:
			Robot(position_type position = { 0, 0 }, Bearing bearing = Bearing::NORTH);
			~Robot();

			position_type get_position() const;
			Bearing get_bearing() const;

			void turn_left();
			void turn_right();

			void advance();

			void execute_sequence(std::string sequence);
	};
}

#endif
