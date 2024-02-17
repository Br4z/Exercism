// URL: https://exercism.org/tracks/cpp/exercises/list-ops DATE: 2024-02-17

#include <cstddef>
#include <vector>

#ifndef LIST_OPS_H
#define LIST_OPS_H


namespace list_ops {
	/**
	 * Appends all items from the second list to the end of the first list.
	 *
	 * @param list1 The first vector list.
	 * @param list2 The second vector list.
	 */
	template <typename T>
	void append(std::vector <T> &list1, std::vector <T> list2) {
		for (int i = 0; i < (int) list2.size(); i++)
			list1.push_back(list2[i]);
	}

	/**
	 * Combines all items from a series of lists into one flattened list.
	 *
	 * @param list A vector of vectors containing items.
	 * @return A flattened vector containing all items from the input vectors.
	 */
	template <typename T>
	std::vector <T> concat(const std::vector <std::vector <T>> &list) {
		std::vector <T> result;

		for (std::vector <T> sub_list : list)
			append(result, sub_list);

		return result;
	}

	/**
	 * Returns the total number of items in the vector list.
	 *
	 * @param list The vector list.
	 * @return The total number of items in the list.
	 */
	template <typename T>
	std::size_t length(std::vector <T> &list) {
		size_t result = 0;

		while (!list.empty()) {
			list.pop_back();
			result++;
		}

		return result;
	}

	/**
	 * Returns a vector containing items from the input list for which predicate is true.
	 *
	 * @tparam T The type of elements in the vector list.
	 * @tparam F The type of the predicate function.
	 * @param list The vector list.
	 * @param predicate The predicate function.
	 * @return A filtered vector containing elements for which the predicate is true.
	 */
	template <typename T, typename F>
	std::vector <T> filter(const std::vector <T> &list, const F &predicate) {
		std::vector <T> result;

		for (T element : list)
			if (predicate(element))
				result.push_back(element);

		return result;
	}

	/**
	 * Returns a vector containing the results of applying function on all items in the input list.
	 *
	 * @tparam T The type of elements in the vector list.
	 * @tparam F The type of the mapping function.
	 * @param list The vector list.
	 * @param f The mapping function.
	 * @return A vector containing the mapped results.
	 */
	template <typename T, typename F>
	std::vector <T> map(const std::vector <T> &list, const F &f) {
		std::vector <T> result;

		for (T element : list)
			result.push_back(f(element));

		return result;
	}

	/**
	 * Returns a vector with all the original items, but in reversed order.
	 *
	 * @tparam T The type of elements in the vector list.
	 * @param list The vector list.
	 * @return A reversed vector.
	 */
	template <typename T>
	std::vector <T> reverse(std::vector <T> list) {
		std::vector <T> result;

		while (!list.empty()) {
			result.push_back(list.back());
			list.erase(list.end() - 1);
		}

		return result;
	}

	/**
	 * Folds (reduces) each item into the accumulator from the right.
	 *
	 * @tparam T The type of elements in the vector list.
	 * @tparam F The type of the folding function.
	 * @param list The vector list.
	 * @param accum The initial accumulator value.
	 * @param f The folding function.
	 * @return The accumulated result after folding.
	 */
	template <typename T, typename F>
	T foldr(std::vector <T> list, T accum, const F &f) {
		while (!list.empty()) {
			accum = f(accum, list.back());
			list.pop_back();
		}

		return accum;
	}

	/**
	 * Folds (reduces) each item into the accumulator from the left.
	 *
	 * @tparam T The type of elements in the vector list.
	 * @tparam F The type of the folding function.
	 * @param list The vector list.
	 * @param accum The initial accumulator value.
	 * @param f The folding function.
	 * @return The accumulated result after folding.
	 */
	template <typename T, typename F>
	T foldl(std::vector <T> &list, T accum, const F &f) {
		return foldr(reverse(list), accum, f);
	}
}

#endif
