// URL: https://exercism.org/tracks/cpp/exercises/perfect-numbers DATE: 2024-01-28

#ifndef PERFECT_NUMBERS_H
#define PERFECT_NUMBERS_H


namespace perfect_numbers {
	enum Number_Class {
		perfect,
		abundant,
		deficient
	};
	Number_Class classify(int number);
}

#endif
