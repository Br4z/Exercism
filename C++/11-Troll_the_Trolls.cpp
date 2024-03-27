// URL: https://exercism.org/tracks/cpp/exercises/troll-the-trolls DATE: 2023-12-08

namespace hellmath {

	/* --------------------------------- TASK 1 --------------------------------- */

	enum class AccountStatus {
		troll,
		guest,
		user,
		mod
	};

	enum class Action {
		read,
		write,
		remove
	};

	/* --------------------------------- TASK 2 --------------------------------- */

	/**
	 * Determines whether a post should be displayed based on the account status of
	 * the poster and viewer.
	 * Trolls can only see posts from other trolls.
	 *
	 * @param poster The account status of the poster.
	 * @param viewer The account status of the viewer.
	 * @return true if the post should be displayed, false otherwise.
	 */
	bool display_post(AccountStatus poster, AccountStatus viewer) {
		if (poster == AccountStatus::troll) {
			return viewer == AccountStatus::troll;
		} else return viewer != AccountStatus::troll;
	}

	/* --------------------------------- TASK 3 --------------------------------- */

	/**
	 * Checks the permission of an action based on the account status.
	 *
	 * @param action The action to be checked.
	 * @param accountStatus The account status of the user.
	 * @return true if the action is allowed for the given account status, false otherwise.
	 */
	bool permission_check(Action action, AccountStatus accountStatus) {
		switch (accountStatus) {
			case AccountStatus::guest:
				return action == Action::read;
			case AccountStatus::troll:
			case AccountStatus::user:
				return action == Action::read || action == Action::write;
			case AccountStatus::mod:
				return action == Action::read || action == Action::write || action == Action::remove;
			default: return false;
		}
	}

	/* --------------------------------- TASK 4 --------------------------------- */

	/**
	 * Determines if a combination of player accounts is valid.
	 * A valid combination is when both players are not guests, and either both
	 * players are trolls or neither player is a troll.
	 *
	 * @param player1 The account status of player 1.
	 * @param player2 The account status of player 2.
	 * @return true if the combination is valid, false otherwise.
	 */
	bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
		if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) return false;
		else if (player1 == AccountStatus::troll) {
			return player2 == AccountStatus::troll;
		} else return player2 != AccountStatus::troll;
	}

	/* --------------------------------- TASK 5 --------------------------------- */

	/**
	 * Determines if player1 has higher priority than player2 based on their account
	 * status.
	 *
	 * @param player1 The account status of player1.
	 * @param player2 The account status of player2.
	 * @return true if player1 has higher priority than player2, false otherwise.
	 */
	bool has_priority(AccountStatus player1, AccountStatus player2) {
		return player1 > player2;
	}
}
