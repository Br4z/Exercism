// URL: https://exercism.org/tracks/cpp/exercises/pascals-triangle DATE: 2024-01-27

#include "pascals_triangle.h"


/**
 * Generate Pascal's Triangle up to a given number of rows.
 *
 * @param rows The number of rows in Pascal's Triangle.
 * @return Pascal's Triangle as a vector of vectors of integers.
 */
std::vector <std::vector <int>> pascals_triangle::generate_rows(int rows) {
	std::vector <std::vector <int>> pascal_triangle;

	if (!rows)
		return pascal_triangle;
	else {
		pascal_triangle.push_back(std::vector <int> { 1 });

		for (int i = 1; i < rows; i++) { // rows - 1
			std::vector <int> row = { 1 };

			for (int j = 1; j < i; j++) // row elements - 2
				row.push_back(pascal_triangle[i - 1][j - 1] + pascal_triangle[i - 1][j]);

			row.push_back(1);
			pascal_triangle.push_back(row);
		}

		return pascal_triangle;
	}
}
