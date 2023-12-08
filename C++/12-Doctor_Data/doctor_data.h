// URL: https://exercism.org/tracks/cpp/exercises/doctor-data DATE: 2023-12-08

#pragma once

#include <string>


namespace star_map {
	enum class System {
		AlphaCentauri,
		BetaHydri,
		DeltaEridani,
		EpsilonEridani,
		Omicron2Eridani,
		Sol
	};
}

namespace heaven {
	class Vessel {
		public:
			std::string name{};
			int generation{};
			star_map::System current_system;
			int busters = 0;


			Vessel(std::string name, int generation = 1, star_map::System current_system = star_map::System::Sol);
			~Vessel();


			Vessel replicate(std::string name);
			void make_buster();
			bool shoot_buster();
	};

	std::string get_older_bob(heaven::Vessel vessel1, heaven::Vessel vessel2);
	bool in_the_same_system(heaven::Vessel vessel1, heaven::Vessel vessel2);
}
