// URL: https://exercism.org/tracks/cpp/exercises/grade-school DATE: 2023-12-15

#include <iostream>

#include "grade_school.h"


/**
 * Displaces the names in a vector starting from the end to a given position.
 *
 * @param names The vector of names.
 * @param position The starting position from where the names should be displaced.
 */
// void displace_names_vector(std::vector <std::string> &names, int position) { // End to position
// 	for (int i = names.size() - 1; i > position; i--)
// 		names[i] = names[i - 1];
// }

/**
 * Displaces the names in a vector starting from a given position to the end.
 *
 * @param names The vector of names.
 * @param position The starting position from where the names should be displaced.
 */
void displace_names_vector(std::vector <std::string> &names, int position) { // Position to end
	if (names.size() > 1) {
		std::string to_replace = names[position];

		for (int i = position + 1; i < (int) names.size(); i++) {
			std::string temp = names[i];
			names[i] = to_replace;
			to_replace = temp;
		}
	}
}

grade_school::school::school() {
	school_roster = { };
}

grade_school::school::~school() {
	school_roster.clear();
}

/**
 * Adds a student to the school list, in ascending order.
 *
 * @param name The name of the student to be added.
 * @param grade The grade of the student.
 */
void grade_school::school::add(std::string name, int grade) {
	std::vector <std::string> &names = school_roster[grade];
	names.resize(names.size() + 1);

	// auto at = std::lower_bound(names.begin(), names.end(), name);
	// names.insert(at, name);

	for (int i = 0; i < (int) names.size(); i++) {
		if (names[i] == "") {
			names[i] = name; break;
		} else if (names[i] > name) {
			displace_names_vector(names, i);
			names[i] = name; break;
		}
	}
}

/**
 * Returns the school roster.
 *
 * @return the school roster.
 */
std::map <int, std::vector <std::string>> grade_school::school::roster() const {
	return school_roster;
}

/**
 * Returns the names associated with a grade in the school roster.
 *
 * @return the names of the people who got that grade in the school roaster.
 */
std::vector <std::string> grade_school::school::grade(int grade) const {
	if (school_roster.find(grade) == school_roster.end())
		return { };

	return school_roster.at(grade);
}
