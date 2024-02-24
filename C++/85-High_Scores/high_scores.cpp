// URL: https://exercism.org/tracks/cpp/exercises/high-scores DATE: 2024-02-20

#include <algorithm>


#include "high_scores.h"


namespace arcade {
	/**
	 * Adds a new score to the high scores list.
	 *
	 * @param score The score to be added.
	 */
	void HighScores::add(int score) {
		scores.push_back(score);
	}

	/**
	 * Returns a copy of the high scores list.
	 *
	 * @return The list of high scores.
	 */
	std::vector <int> HighScores::list_scores() {
		return scores;
	}

	/**
	 * Returns the latest score that was added.
	 *
	 * @return The latest score.
	 */
	int HighScores::latest_score() {
		return scores.back();
	}

	/**
	 * Returns the highest score in the high scores list.
	 *
	 * @return The highest score.
	 */
	int HighScores::personal_best() {
		return *std::max_element(scores.begin(), scores.end());
	}

	/**
	 * Returns the top three scores in descending order.
	 * If there are less than three scores, all scores are returned.
	 *
	 * @return The top three scores.
	 */
	std::vector <int> HighScores::top_three() {
		std::vector <int> scores_copy = scores;

		std::sort(scores_copy.begin(), scores_copy.end(), std::greater <int>());

		if (scores_copy.size() >= 3)
			return { scores_copy.begin(), scores_copy.begin() + 3 };
		else
			return scores_copy;
	}
}
