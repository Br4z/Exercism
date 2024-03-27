// URL: https://exercism.org/tracks/cpp/exercises/yacht DATE: 2024-02-21

#include <map>
#include <string>
#include <vector>

#ifndef YACHT_H
#define YACHT_H


namespace yacht {
	std::map <int, int> analyze_dices(const std::vector <int> &dices);
	int score(std::vector <int> dices, std::string category);
}

#endif
