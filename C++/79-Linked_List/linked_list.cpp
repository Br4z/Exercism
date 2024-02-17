// URL: https://exercism.org/tracks/cpp/exercises/linked-list DATE: 2024-02-13

#include <stdexcept>

#include "linked_list.h"


/**
 * Adds an element to the end of the linked list.
 *
 * @param value The value to be added to the linked list.
 * @tparam T The type of the elements in the linked list.
 */
template <typename T>
void linked_list::List <T>::push(const T &value) {
	Node <T>* node = new Node <T>(value);

	if (!head)
		head = tail = node;
	else {
		node -> previous = tail;
		tail -> next = node;
		tail = node;
	}

	size++;
}

/**
 * Removes and returns the last element of the linked list.
 *
 * @return The value of the removed element.
 * @throw std::length_error if popping from an empty list.
 * @tparam T The type of the elements in the linked list.
 */
template <typename T>
T linked_list::List <T>::pop() {
	if (size == 0)
		throw std::length_error("Popping from an empty list");

	Node <T>* old_tail = tail;
	T value = old_tail -> value;

	if (head == tail)
		head = tail = nullptr;
	else {
		tail = tail -> previous;
		tail -> next = nullptr;
	}

	delete old_tail;
	size--;

	return value;
}

/**
 * Removes and returns the first element of the linked list.
 *
 * @return The value of the removed element.
 * @throw std::length_error if shifting from an empty list.
 * @tparam T The type of the elements in the linked list.
 */
template <typename T>
T linked_list::List <T>::shift() {
	if (size == 0)
		throw std::length_error("Shifting from an empty list");

	Node <T>* old_head = head;
	T value = old_head -> value;

	if (head == tail)
		head = tail = nullptr;
	else {
		head = head -> next;
		head -> previous = nullptr;
	}

	delete old_head;
	size--;

	return value;
}

/**
 * Adds an element to the start of the linked list.
 *
 * @param value The value to be added to the linked list.
 * @tparam T The type of the elements in the linked list.
 */
template <typename T>
void linked_list::List <T>::unshift(const T &value) {
	Node <T>* node = new Node <T> (value);

	if (!head)
		head = tail = node;
	else {
		head -> previous = node;
		node -> next = head;
		head = node;
	}

	size++;
}

/**
 * Returns the total number of elements in the current list.
 *
 * @return The number of elements in the linked list.
 * @tparam T The type of the elements in the linked list.
 */
template <typename T>
int linked_list::List <T>::count() const {
	return size;
}

/**
 * Removes the first occurrence of the specified value from the linked list.
 *
 * @details If the value appears more than once, only the first occurrence is removed.
 * @param value The value to be removed from the linked list.
 * @tparam T The type of the elements in the linked list.
 */
template <typename T>
void linked_list::List <T>::erase(const T &value) {
	if (size == 0)
		throw std::length_error("Erasing from an empty list");

	Node <T> * node = head;

	while (node && node -> value != value)
		node = node -> next;

	if (node) {
		if (node == head)
			shift();
		else if (node == tail)
			pop();
		else {
			node -> previous -> next = node -> next;
			node -> next -> previous = node -> previous;

			delete node;
			size--;
		}
	}
}

// template class linked_list::List <int>;
