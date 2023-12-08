// URL: https://exercism.org/tracks/cpp/exercises/election-day DATE: 2023-12-07

#include <string>
#include <vector>


namespace election {
	struct ElectionResult {
		std::string name{};
		int votes{};
	};

	/* --------------------------------- TASK 1 --------------------------------- */

	// vote_count takes a reference to an 'ElectionResult' as an argument and will
	// return the number of votes in the 'ElectionResult'.
	int vote_count(ElectionResult &electionResult) {
		return electionResult.votes;
	}

	/* --------------------------------- TASK 2 --------------------------------- */

	// increment_vote_count takes a reference to an 'ElectionResult' as an argument
	// and a number of votes (int), and will increment the 'ElectionResult' by that
	// number of votes.
	void increment_vote_count(ElectionResult &electionResult, int votes) {
		electionResult.votes += votes;
	}

	/* --------------------------------- TASK 3 --------------------------------- */

	// determine_result receives the reference to a final_count and returns a
	// reference to the 'ElectionResult' of the new president. It also changes the
	// name of the winner by prefixing it with "President". The final count is given
	// in the form of a 'reference' to 'std::vector <ElectionResult>', a vector with
	// 'ElectionResults' of all the participating candidates.

	ElectionResult& determine_result(std::vector<ElectionResult> &final_count) {
		int winner_index = 0;

		for (int i = 1; i < final_count.size(); i++) {
			if (vote_count(final_count[i]) > vote_count(final_count[winner_index])) winner_index = i;
		}

		ElectionResult &winner = final_count[winner_index];

		winner.name = "President " + winner.name;

		return winner;
	}
}
