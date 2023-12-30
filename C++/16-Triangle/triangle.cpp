// URL: https://exercism.org/tracks/cpp/exercises/triangle DATE: 2023-12-09

#include <stdexcept>

#include "triangle.h"


/**
 * Determines the flavor of a triangle based on its side lengths.
 * In case the triangle is illegal, an exception is thrown.
 *
 * @param a The length of side a.
 * @param b The length of side b.
 * @param c The length of side c.
 * @return The flavor of the triangle.
 */
triangle::flavor triangle::kind(double a, double b, double c) {
	bool are_all_sides_positive = a > 0 && b > 0 && c > 0;
	bool first_inequality = a + b >= c;
	bool second_inequality = a + c >= b;
	bool third_inequality = b + c >= a;
	bool are_all_inequalities_satisfied = first_inequality && second_inequality && third_inequality;

	if (!are_all_sides_positive)
		throw std::domain_error("Triangles with negative sides are illegal");
	else if (!are_all_inequalities_satisfied)
		throw std::domain_error("Triangles violating triangle inequality are illegal");
	else {
		if (a == b && b == c)
			return triangle::flavor::equilateral;
		else if (a == b || b == c || a == c)
			return triangle::flavor::isosceles;
		else
			return triangle::flavor::scalene;
	}
}
