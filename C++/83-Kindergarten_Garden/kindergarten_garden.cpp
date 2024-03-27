// URL: https://exercism.org/tracks/cpp/exercises/kindergarten-garden DATE: 2024-02-17

#include <stdexcept>

#include "kindergarten_garden.h"


/**
 * Converts a character to the corresponding plant type.
 *
 * @param letter The character representing the plant.
 * @return the corresponding plant type.
 * @throw std::domain_error If the letter is invalid.
 */
kindergarten_garden::Plants kindergarten_garden::get_plant(char letter) {
	switch (letter) {
		case 'C':
			return kindergarten_garden::Plants::clover;
		case 'G':
			return kindergarten_garden::Plants::grass;
		case 'V':
			return kindergarten_garden::Plants::violets;
		case 'R':
			return kindergarten_garden::Plants::radishes;
		default:
			throw std::domain_error("Invalid letter");
	}
}

/**
 * Retrieves the plants assigned to a specific student in the kindergarten garden.
 *
 * @param garden A string representing the garden layout.
 * @param student The name of the student whose plants are to be retrieved.
 * @return an array of four Plants representing the assigned plants to the student.
 */
std::array <kindergarten_garden::Plants, 4> kindergarten_garden::plants(std::string garden, std::string student) {
	std::array <kindergarten_garden::Plants, 4> plants;

	int student_position = 2 * (student[0] - 'A');
	int split_position = garden.find('\n');

	std::string first_row = garden.substr(0, split_position);
	std::string second_row = garden.substr(split_position + 1, garden.length());

	plants[0] = get_plant(first_row[student_position]);
	plants[1] = get_plant(first_row[student_position + 1]);
	plants[2] = get_plant(second_row[student_position]);
	plants[3] = get_plant(second_row[student_position + 1]);

	return plants;
}
