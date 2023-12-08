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

			int get_health() { return health; }

			/* --------------------------------- TASK 2 --------------------------------- */

			bool hit() {
				if (health > 0) health--;

				return true;
			}

			/* --------------------------------- TASK 3 --------------------------------- */

			bool is_alive() {
				return health > 0;
			}

			/* --------------------------------- TASK 4 --------------------------------- */

			bool teleport(int x_new, int y_new) {
				x_coordinate = x_new;
				y_coordinate = y_new;

				return true;
			}

			/* --------------------------------- TASK 5 --------------------------------- */

			bool collision_detection(Alien alien) {
				return x_coordinate == alien.x_coordinate && y_coordinate == alien.y_coordinate;
			}
	};
}
