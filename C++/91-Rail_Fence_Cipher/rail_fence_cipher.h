// URL: https://exercism.org/tracks/cpp/exercises/rail-fence-cipher DATE: 2024-08-28

#include <string>

#ifndef RAIL_FENCE_CIPHER_H
#define RAIL_FENCE_CIPHER_H


namespace rail_fence_cipher {
	std::string encode(const std::string &plain_text, int number_rails);
	std::string decode(const std::string &cipher_text, int number_rails);
}

#endif
