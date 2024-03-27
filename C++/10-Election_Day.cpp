// URL: https://exercism.org/tracks/cpp/exercises/election-day DATE: 2023-12-07

#include <string>
#include <vector>


namespace election {
	struct ElectionResult {
		std::string name{ }; // Name of the candidate
		int votes{ }; // Number of votes received by the candidate
	};

	/* --------------------------------- TASK 1 --------------------------------- */

	/**
	 * Returns the number of votes in the given ElectionResult.
	 *
	 * @param electionResult The ElectionResult to count votes from.
	 * @return the number of votes in the ElectionResult.
	 */
	int vote_count(ElectionResult &electionResult) {
		return electionResult.votes;
	}

	/* --------------------------------- TASK 2 --------------------------------- */

	/**
	 * Increments the vote count of the given ElectionResult by the specified number
	 * of votes.
	 *
	 * @param electionResult The ElectionResult to increment the vote count for.
	 * @param votes The number of votes to increment by.
	 */
	void increment_vote_count(ElectionResult &electionResult, int votes) {
		electionResult.votes += votes;
	}

	/* --------------------------------- TASK 3 --------------------------------- */

	/**
	 * Determines the result of the election based on the final count of
	 * votes.
	 *
	 * @param final_count The final count of votes for all participating candidates.
	 * @return a reference to the ElectionResult of the new president.
	 * @details The name of the winner is changed by prefixing it with "President".
	 */
	ElectionResult& determine_result(std::vector <ElectionResult> &final_count) {
		int winner_index = 0;

		for (int i = 1; i < final_count.size(); i++)
			if (vote_count(final_count[i]) > vote_count(final_count[winner_index])) winner_index = i;

		ElectionResult &winner = final_count[winner_index];

		winner.name = "President " + winner.name;

		return winner;
	}
}
