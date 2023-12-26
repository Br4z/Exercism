// URL: https://exercism.org/tracks/cpp/exercises/say DATE: 2023-12-24

#include <string>

#ifndef SAY_H
#define SAY_H


namespace say {
	std::string number_to_english(int n);
	std::string chunk_to_english(int n);
	std::string in_english(long long n);
}

#endif
