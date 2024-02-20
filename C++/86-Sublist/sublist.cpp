// URL: https://exercism.org/tracks/cpp/exercises/sublist DATE: 2024-02-20

#include <algorithm>

#include "sublist.h"

/**
 * Checks if there is a match between the sublist and the superlist starting from a specific index.
 *
 * @param superlist The superlist to check against.
 * @param sublist The sublist to check.
 * @param i The index in the superlist to start the comparison.
 * @return True if the sublist matches the superlist from the given index, false otherwise.
 */
bool is_match(const std::vector <int> &superlist, const std::vector <int> &sublist , int i) {
	int sublist_size = sublist.size();
	int j = 0;

	while (j < sublist_size) {
		if (superlist[i] != sublist[j]) {
			return false;
		} else {
			i++;
			j++;
		}
	}

	return true;
}

/**
 * Checks if one list is a sublist of another.
 *
 * @param superlist The potential superlist.
 * @param sublist The potential sublist.
 * @return True if sublist is a sublist of superlist, false otherwise.
 */
bool sublist::is_sublist(const std::vector <int> &superlist, const std::vector <int> &sublist) {
	int superlist_size = superlist.size(), sublist_size = sublist.size();

	for (int i = 0; i <= superlist_size - sublist_size; i++)
		if (is_match(superlist, sublist, i)) // std::equal(superlist.begin() + i, superlist.begin() + i + sublist_size, sublist.begin())
			return true;

	return false;
}

/**
 * Compares two lists to determine their relationship.
 *
 * @param list1 The first list.
 * @param list2 The second list.
 * @return The relationship between the two lists.
 */
sublist::List_comparison sublist::sublist(const std::vector <int> &list1, const std::vector <int> &list2) {
	if (list1 == list2)
		return sublist::List_comparison::equal;
	else {
		int list1_size = list1.size();
		int list2_size = list2.size();

		if (list1_size > list2_size && is_sublist(list1, list2)) // list2 might be a sublist of list1
			return List_comparison::superlist;
		else if (list2_size > list1_size && is_sublist(list2, list1)) // list1 might be a sublist of list2
			return List_comparison::sublist;

		return  List_comparison::unequal;
	}
}
