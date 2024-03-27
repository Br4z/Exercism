// URL: https://exercism.org/tracks/cpp/exercises/anagram DATE: 2024-01-21

#include <string>
#include <vector>

#ifndef ANAGRAM_H
#define ANAGRAM_H


namespace anagram {
	class anagram {
		private:
			std::string word;
		public:
			anagram(std::string word);


			bool is_anagram(std::string canditate);
			std::vector <std::string> matches(std::vector <std::string> candidates);
	};
}

#endif
