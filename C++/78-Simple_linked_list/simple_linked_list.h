// URL: https://exercism.org/tracks/cpp/exercises/simple-linked-list DATE: 2024-02-10

#include <cstddef>

#ifndef SIMPLE_LINKED_LIST_H
#define SIMPLE_LINKED_LIST_H


namespace simple_linked_list {
	class List {
		private:
			struct Element {
				int data{ };
				Element(int data) : data{data} { };
				Element* next{ nullptr };
			};

			Element* head{ nullptr };
			std::size_t current_size{ 0 };
		public:
			List() = default;
			~List();

			List(const List&) = delete;
			List& operator=(const List&) = delete;
			List(List&&) = delete;
			List& operator=(List&&) = delete;

			std::size_t size() const;
			void push(int entry);
			int pop();
			void reverse();
	};
}

#endif
