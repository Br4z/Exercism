// URL: https://exercism.org/tracks/cpp/exercises/high-scores DATE: 2024-02-20

#include <vector>

#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H


namespace arcade {
	class HighScores {
		private:
			std::vector <int> scores;

		public:
			HighScores(std::vector <int> scores) : scores(scores) { };

			void add(int score);
			std::vector <int> list_scores();
			int latest_score();
			int personal_best();
			std::vector <int> top_three();
	};
}

#endif
