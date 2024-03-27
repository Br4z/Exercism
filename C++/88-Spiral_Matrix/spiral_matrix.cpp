// URL: https://exercism.org/tracks/cpp/exercises/spiral-matrix DATE: 2024-02-22

#include "spiral_matrix.h"


/**
 * Generates a square matrix of numbers in spiral order.
 *
 * @param size The size of the square matrix.
 * @return the generated square matrix in spiral order.
 */
std::vector <std::vector <uint32_t>> spiral_matrix::spiral_matrix(int size) {
	std::vector <std::vector <uint32_t>> matrix(size, std::vector <uint32_t>(size));

	int n = 1;
	int top = 0, bottom = size - 1, left = 0, right = size - 1;

	while (top <= bottom && left <= right) {
		for (int i = left; i <= right; i++)
			matrix[top][i] = n++;

		top++;

		for (int i = top; i <= bottom; ++i)
			matrix[i][right] = n++;

		right--;

		if (top <= bottom) {
			for (int i = right; i >= left; i--)
				matrix[bottom][i] = n++;
			bottom--;
		}

		if (left <= right) {
			for (int i = bottom; i >= top; i--)
				matrix[i][left] = n++;
			left++;
		}
	}

	return matrix;
}
