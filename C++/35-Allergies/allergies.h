// URL: https://exercism.org/tracks/cpp/exercises/allergies DATE: 2023-12-29

#include <bits/stdc++.h>
#include <string>

#ifndef ALLERGIES_H
#define ALLERGIES_H


namespace allergies {
	class allergy_test {
		private:
			int score;
			std::unordered_set <std::string> allergies;
		public:
			allergy_test(int score);
			~allergy_test();

			bool is_allergic_to(std::string allergic);
			std::unordered_set <std::string> get_allergies();
	};
}

#endif
