// URL: https://exercism.org/tracks/cpp/exercises/grade-school DATE: 2023-12-15

#include <iostream>

#include "grade_school.h"


// void displace_names_vector(std::vector <std::string> &names, int position) { // End to position
// 	for (int i = names.size() - 1; i > position; i--) {
// 		names[i] = names[i - 1];
// 	}
// }

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

void grade_school::print_names(std::vector <std::string> names) {
	for (int i = 0; i < (int) names.size(); i++) {
		std::cout << names[i] << std::endl;
	}
}

grade_school::school::school() {
	school_roster = {};
}

grade_school::school::~school() {
	school_roster.clear();
}

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

std::map <int, std::vector <std::string>> grade_school::school::roster() const {
	return school_roster;
}

std::vector <std::string> grade_school::school::grade(int grade) const {
	if (school_roster.find(grade) == school_roster.end()) {
		return {};
	}
	return school_roster.at(grade);
}
