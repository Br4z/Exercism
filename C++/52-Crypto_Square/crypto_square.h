// URL: https://exercism.org/tracks/cpp/exercises/crypto-square DATE: 2024-01-18

#include <string>
#include <vector>

#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H


namespace crypto_square {
	class cipher {
		private:
			std::string text, normalized_text, ciphered_text;
			int c, r;

		public:
			cipher(std::string text);

			std::string normalize_plain_text();
			std::vector <std::string> plain_text_segments();
			std::string cipher_text();
			std::string normalized_cipher_text();
	};
}

#endif
