// URL: https://exercism.org/tracks/cpp/exercises/robot-simulator DATE: 2024-02-08

#include "robot_simulator.h"


robot_simulator::Robot::Robot(position_type position, robot_simulator::Bearing bearing) : position_(position), bearing_(bearing) {

}

robot_simulator::Robot::~Robot() {

}

/**
 * Gets the current position of the Robot.
 *
 * @return The {x, y} coordinates of the Robot's position.
 */
position_type robot_simulator::Robot::get_position() const {
	return position_;
}

/**
 * Gets the current direction the Robot is facing.
 *
 * @return The current bearing of the Robot.
 */
robot_simulator::Bearing robot_simulator::Robot::get_bearing() const {
	return bearing_;
}

/**
 * Turns the Robot 90 degrees to the left.
 */
void robot_simulator::Robot::turn_left() {
	if (bearing_ == Bearing::NORTH)
		bearing_ = Bearing::WEST;
	else
		bearing_ = static_cast <Bearing>(static_cast <int>(bearing_) - 1);
}

/**
 * Turns the Robot 90 degrees to the right.
 */
void robot_simulator::Robot::turn_right() {
	if (bearing_ == Bearing::WEST)
		bearing_ = Bearing::NORTH;
	else
		bearing_ = static_cast <Bearing>(static_cast <int>(bearing_) + 1);
}

/**
 * Moves the Robot one unit in the direction it is currently facing.
 */
void robot_simulator::Robot::advance() {
	auto& [x, y] = position_;

	switch (bearing_) {
		case Bearing::NORTH:
			y++;
			break;
		case Bearing::EAST:
			x++;
			break;
		case Bearing::SOUTH:
			y--;
			break;
		case Bearing::WEST:
			x--;
			break;
	}
}

/**
 * Executes a sequence of instructions on the Robot.
 *
 * @param sequence A string containing instructions to turn left ('L'), turn
 * right ('R'), or advance ('A').
 */
void robot_simulator::Robot::execute_sequence(std::string sequence) {
	for (char& instruction : sequence)
		switch (instruction) {
			case 'L':
				turn_left();
				break;
			case 'R':
				turn_right();
				break;
			case 'A':
				advance();
				break;
		}
}
