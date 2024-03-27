// URL: https://exercism.org/tracks/cpp/exercises/binary-search-tree DATE: 2024-01-22

#include <memory>

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H


namespace binary_search_tree {
	template <typename T>
	class binary_tree {
		private:
			T value;

			binary_tree <T>* parent_node;
			std::unique_ptr <binary_tree <T>> left_node, right_node;
		public:
			binary_tree(const T &value) : value(value),
				parent_node(nullptr), left_node(nullptr), right_node(nullptr) {

			}

			/**
			 * Get the data value stored in the node.
			 *
			 * @return the data value of the node.
			*/
			const T& data() {
				return value;
			}

			/**
			 * Get the left child node of the current node.
			 *
			 * @return a reference to the left child node.
			 */
			const std::unique_ptr <binary_tree <T>>& left() {
				return left_node;
			}

			/**
			 * Get the right child node of the current node.
			 *
			 * @return a reference to the right child node.
			 */
			const std::unique_ptr <binary_tree <T>>& right() {
				return right_node;
			}

			/**
			 * Insert a new value into the binary tree.
			 *
			 * @param value The value to be inserted into the tree.
			 */
			void insert(const T &value) {
				auto& node = value <= this -> value ? left_node : right_node;

				if (!node) {
					node = std::unique_ptr <binary_tree <T>>(new binary_tree <T>(value));
					node.get() -> parent_node = this;
				} else
					node -> insert(value);
			}


			class iterator {
				private:
					binary_tree <T>* actual_node;
				public:
					iterator(binary_tree* node) : actual_node(node) { // Starting with the minimum node
						if (actual_node)
							while (actual_node -> left_node)
								actual_node = (actual_node -> left_node).get();
					}

					/**
					 * Check if two iterators are not equal.
					 *
					 * @param other The iterator to compare with.
					 * @return true if the iterators are not equal, false otherwise.
					 */
					bool operator !=(const iterator &other) const {
						return actual_node != other.actual_node;
					}

					/**
					 * Dereference operator to get the value at the current iterator position.
					 *
					 * @return a reference to the value at the current iterator position.
					 */
					T& operator *() const {
						return actual_node -> value;
					}

					/**
					 * Prefix increment operator to move to the next iterator position.
					 *
					 * @return a reference to the updated iterator.
					 */
					iterator& operator++() { // Find successor node
						if (actual_node -> right_node) {
							actual_node = (actual_node -> right_node).get();

							while (actual_node -> left_node)
								actual_node = (actual_node -> left_node).get();
						} else {
							auto successor = actual_node -> parent_node;

							while (successor && actual_node == (successor -> right_node).get()) {
								actual_node = successor;
								successor = successor -> parent_node;
							}
							actual_node = successor;
						}
						return *this;
					}
			};

			/**
			 * Get the iterator pointing to the beginning of the binary search tree.
			 *
			 * @return an iterator pointing to the minimum node.
			 */
			iterator begin() {
				return iterator(this);
			}

			/**
			 * Get the iterator pointing to the end of the binary search tree.
			 *
			 * @return an iterator pointing to nullptr.
			*/
			iterator end() {
				return iterator(nullptr);
			}
	};
}

#endif
