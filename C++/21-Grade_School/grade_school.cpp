// URL: https://exercism.org/tracks/cpp/exercises/grade-school DATE: 2023-12-15

#include <iostream>

#include "grade_school.h"


void grade_school::print_names(std::vector <std::string> names) {
	for (long unsigned int i = 0; i < names.size(); i++) {
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
	std::vector <std::string>& names = school_roster[grade];
	names.resize(names.size() + 1);

	// auto at = std::lower_bound(names.begin(), names.end(), name);
	// names.insert(at, name);

	for (long unsigned int i = 0; i < names.size(); i++) {
		if (names[i] > name || names[i] == "") {
			names.insert(names.begin() + i, name);
			names.pop_back(); break; // Remove the last name (empty name)
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
