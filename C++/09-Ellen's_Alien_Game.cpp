// URL: https://exercism.org/tracks/cpp/exercises/ellens-alien-game DATE: 2023-12-07

namespace targets {
	class Alien {
		private:
			int health = 3;

		public:

			/* --------------------------------- TASK 1 --------------------------------- */

			int x_coordinate;
			int y_coordinate;

			Alien(int x, int y) {
				x_coordinate = x;
				y_coordinate = y;
			}

			~Alien() { }

			/**
			 * Get the health value of the alien.
			 *
			 * @return int The health value of the alien.
			 */
			int get_health() { return health; }

			/* --------------------------------- TASK 2 --------------------------------- */

			/**
			 * Decreases the health of the alien by 1.
			 *
			 * @return true if the alien is still alive after being hit, false otherwise.
			 */
			bool hit() {
				if (health > 0)
					health--;

				return true;
			}

			/* --------------------------------- TASK 3 --------------------------------- */

			/**
			 * Checks if the alien is alive.
			 *
			 * @return true if the alien's health is greater than 0, false otherwise.
			 */
			bool is_alive() {
				return health > 0;
			}

			/* --------------------------------- TASK 4 --------------------------------- */

			/**
			 * Teleports the alien to the specified coordinates.
			 *
			 * @param x_new The new x-coordinate of the alien.
			 * @param y_new The new y-coordinate of the alien.
			 * @return true if the teleportation was successful, false otherwise.
			 */
			bool teleport(int x_new, int y_new) {
				x_coordinate = x_new;
				y_coordinate = y_new;

				return true;
			}

			/* --------------------------------- TASK 5 --------------------------------- */

			/**
			 * Checks if there is a collision between the current alien and another alien.
			 *
			 * @param alien The alien to check for collision with.
			 * @return true if there is a collision, false otherwise.
			 */
			bool collision_detection(Alien alien) {
				return x_coordinate == alien.x_coordinate && y_coordinate == alien.y_coordinate;
			}
	};
}
