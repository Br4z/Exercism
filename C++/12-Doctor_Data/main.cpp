#include <iostream>

#include "doctor_data.h"


int main() {
	heaven::Vessel bob{ "Robert Johansson", 1};
	heaven::Vessel will { "Riker", 2, star_map::System::BetaHydri };

	bob.make_buster();

	std::cout << bob.shoot_buster();
	return 0;
}
