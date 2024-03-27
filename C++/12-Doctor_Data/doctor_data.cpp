// URL: https://exercism.org/tracks/cpp/exercises/doctor-data DATE: 2023-12-08

#include "doctor_data.h"


heaven::Vessel::Vessel(std::string name, int generation, star_map::System current_system) :
	name(name), generation(generation), current_system (current_system) {

}

heaven::Vessel::~Vessel() {

}

/**
 * Replicates the current vessel with a new name.
 *
 * @param name The name of the new vessel.
 * @return a new vessel with the specified name, incremented generation, and the
 * same current system.
 */
heaven::Vessel heaven::Vessel::replicate(std::string name) {
	heaven::Vessel newVessel = heaven::Vessel(name, generation + 1, current_system);

	return newVessel;
}

/**
 * Increases the count of busters in the vessel.
 */
void heaven::Vessel::make_buster() {
	busters++;
}

/**
 * Decreases the number of busters and returns true if buster
 * was shot, false otherwise (the case where no buster
 * was available).
 *
 * @return true if busters are available, false otherwise.
 */
bool heaven::Vessel::shoot_buster() {
	if (busters > 0) {
		busters--;

		return true;
	} else
		return false;
}

/**
 * Returns the name of the vessel that is older based on their generation.
 * A vessel is older if its generation is less than the other vessel.
 *
 * @param vessel1 The first vessel.
 * @param vessel2 The second vessel.
 * @return the name of the older vessel.
 */
std::string heaven::get_older_bob(heaven::Vessel vessel1, heaven::Vessel vessel2) {
	return vessel1.generation < vessel2.generation ? vessel1.name : vessel2.name;
}

/**
 * Checks if two vessels are in the same system.
 *
 * @param vessel1 The first vessel.
 * @param vessel2 The second vessel.
 * @return true if both vessels are in the same system, false otherwise.
 */
bool heaven::in_the_same_system(heaven::Vessel vessel1, heaven::Vessel vessel2) {
	return vessel1.current_system == vessel2.current_system;
}
