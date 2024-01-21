// URL: https://exercism.org/tracks/cpp/exercises/pacman-rules DATE: 2023-12-07

/* --------------------------------- TASK 1 --------------------------------- */

/**
 * Determines if Pacman can eat a ghost.
 *
 * @param power_pellet_active Indicates if a power pellet is active.
 * @param touching_ghost Indicates if Pacman is touching a ghost.
 * @return True if Pacman can eat the ghost, false otherwise.
 */
bool can_eat_ghost(bool power_pellet_active, bool touching_ghost) {
	return power_pellet_active && touching_ghost;
}

/* --------------------------------- TASK 2 --------------------------------- */

/**
 * Determines if the player has scored in the game.
 * A player scores if they are touching a power pellet or a dot.
 *
 * @param touching_power_pellet Indicates if the player is touching a power pellet
 * @param touching_dot Indicates if the player is touching a dot
 * @return true if the player has scored, false otherwise
 */
bool scored(bool touching_power_pellet, bool touching_dot) {
	return touching_power_pellet || touching_dot;
}

/* --------------------------------- TASK 3 --------------------------------- */

/**
 * Determines if the player has lost the game.
 * The player loses if the power pellet is not active and they are touching a
 * ghost.
 *
 * @param power_pellet_active Indicates if the power pellet is active
 * @param touching_ghost Indicates if the player is touching a ghost
 * @return true if the player has lost, false otherwise
 */
bool lost(bool power_pellet_active, bool touching_ghost) {
	return !power_pellet_active && touching_ghost;
}

/* --------------------------------- TASK 4 --------------------------------- */

/**
 * Determines if the player has won the game.
 *
 * @param has_eaten_all_dots Indicates whether the player has eaten all the dots.
 * @param power_pellet_active Indicates whether the power pellet is active.
 * @param touching_ghost Indicates whether the player is touching a ghost.
 * @return true if the player has won, false otherwise.
 */
bool won(bool has_eaten_all_dots, bool power_pellet_active,  bool touching_ghost) {
	return has_eaten_all_dots && !lost(power_pellet_active, touching_ghost);
}
