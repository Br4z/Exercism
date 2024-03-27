// URL: https://exercism.org/tracks/cpp/exercises/triangle DATE: 2023-12-09

#ifndef TRIANGLE_H
#define TRIANGLE_H


namespace triangle {
	enum class flavor {
		equilateral,
		isosceles,
		scalene
	};

	flavor kind(double a, double b, double c);
}

#endif
