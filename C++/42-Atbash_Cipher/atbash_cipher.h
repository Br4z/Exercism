// URL: https://exercism.org/tracks/cpp/exercises/atbash-cipher DATE: 2024-01-06

#include <string>

#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

namespace atbash_cipher {
	std::string encode(std::string message);
	std::string decode(std::string message);
}

#endif
