// URL: https://exercism.org/tracks/cpp/exercises/linked-list DATE: 2024-02-13

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


namespace linked_list {
	template <typename T>
	struct Node {
		T value;
		Node* previous;
		Node* next;
		Node(const T &value) : value(value), previous(nullptr), next(nullptr) { }
	};

	template <typename T>
	class List {
		private:
			Node <T>* head;
			Node <T>* tail;

			int size;
		public:
			List() : head(nullptr), tail(nullptr), size(0) { };

			void push(const T &value);
			T pop();
			T shift();
			void unshift(const T &value);
			int count() const;
			void erase(const T &value);
	};
}

#endif
