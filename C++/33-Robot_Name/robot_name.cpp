// URL: https://exercism.org/tracks/cpp/exercises/robot-name DATE: 2023-12-27

#include <cstdlib>

#include "robot_name.h"


std::unordered_set <std::string> robot_name::robot::existing_names = { };

/**
 * Assigns a unique name to the robot.
 *
 * This function generates a random name for the robot by combining two
 * uppercase letters and four digits.
 */
void robot_name::robot::assign_name() {
	std::string robot_name = "     ";

	while (true) {
		for (int i = 0; i < 2; i++)
			robot_name[i] = 'A' + rand() % 26;
		for (int i = 2; i < 6; i++)
			robot_name[i] = '0' + rand() % 10;

		bool is_name_available = robot_name::robot::existing_names.find(robot_name) == robot_name::robot::existing_names.end();

		if (is_name_available)
			robot_name::robot::existing_names.emplace(robot_name); break;
	}

	this -> robot_name = robot_name;
}

robot_name::robot::robot() {
	assign_name();
}

robot_name::robot::~robot() {

}

/**
 * Returns the name of the robot.
 *
 * @return string The name of the robot.
 */
std::string robot_name::robot::name() const {
	return robot_name;
}

/**
 * Resets the robot's name by assigning a new name.
 */
void robot_name::robot::reset() {
	assign_name();
}
