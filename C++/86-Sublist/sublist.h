// URL: https://exercism.org/tracks/cpp/exercises/sublist DATE: 2024-02-20

#include <vector>

#ifndef SUBLIST_H
#define SUBLIST_H


namespace sublist {
	enum class List_comparison {
		equal,
		sublist,
		superlist,
		unequal
	};

	bool is_sublist(const std::vector <int> &list1, const std::vector <int> &list2);

	List_comparison sublist(const std::vector <int> &list1, const std::vector <int> &list2);
}

#endif
