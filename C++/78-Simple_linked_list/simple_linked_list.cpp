// URL: https://exercism.org/tracks/cpp/exercises/simple-linked-list DATE: 2024-02-10

#include "simple_linked_list.h"

#include <stdexcept>
#include <iostream>


namespace simple_linked_list {
	List::~List() {
		while (current_size > 0)
			pop();
	}

	/**
	 * Gets the current size of the linked list.
	 *
	 * @return The current size of the linked list.
	 */
	std::size_t List::size() const {
		return current_size;
	}

	/**
	 * @brief Adds a new element to the beginning of the linked list.
	 *
	 * @param entry The integer value to be added to the linked list.
	 */
	void List::push(int entry) {
		Element* element = new Element(entry);

		element -> next = head;
		head = element;

		current_size++;
	}

	/**
	 * Removes the first element from the linked list.
	 *
	 * @return The value of the removed element.
	 * @throw std::length_error if the linked list is empty.
	 */
	int List::pop() {
		if (current_size == 0)
			throw std::length_error("Linked list is empty");

		Element* old_head = head;
		head = head -> next;

		int old_head_entry = old_head -> data;

		delete old_head;
		old_head = nullptr;

		current_size--;

		return old_head_entry;
	}

	/**
	 * Reverses the linked list.
	 */
	void List::reverse() {
		/*
		// This way does not work cause we delete the original head
		// pointer in the pop method
		List reversed;
		int original_size = current_size;

		while (current_size > 0) {
			int entry = pop();
			reversed.push(entry);
		}

		head = reversed.head;
		current_size = original_size;
		*/
		Element* prev = nullptr;
		Element* current = head;
		Element* next = nullptr;

		while (current) {
			next = current -> next;
			current -> next = prev;
			prev = current;
			current = next;
		}

		head = prev;
	}
}

int main() {
	simple_linked_list::List list;

	list.push(30);
	list.push(20);
	list.push(10);

	list.reverse();

	std::cout << list.pop() << std::endl;
}
