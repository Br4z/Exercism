// URL: https://exercism.org/tracks/cpp/exercises/vehicle-purchase DATE: 2023-12-07

#include <string>


namespace vehicle_purchase {
	/* --------------------------------- TASK 1 --------------------------------- */

	/**
	 * Determines whether a license is needed to drive a type of vehicle. Only "car"
	 * and "truck" require a license.
	 *
	 * @param kind The type of vehicle.
	 * @return True if a license is needed, false otherwise.
	 */
	bool needs_license(std::string kind){
		return kind == "car" or kind == "truck";
	}

	/* --------------------------------- TASK 2 --------------------------------- */

	/**
	 * Recommends a vehicle for selection. It always recommends the vehicle that
	 * comes first in lexicographical order.
	 *
	 * @param option1 The first vehicle option.
	 * @param option2 The second vehicle option.
	 * @return The recommended vehicle option.
	 */
	std::string choose_vehicle(std::string option1, std::string option2) {
		std::string betterOption;

		if (option2 > option1)
			betterOption = option1;
		else
			betterOption = option2;

		return betterOption + " is clearly the better choice.";
	}

	/* --------------------------------- TASK 3 --------------------------------- */

	/**
	 * Calculates how much a vehicle can resell for at a certain age.
	 *
	 * @param original_price The original price of the vehicle.
	 * @param age The age of the vehicle.
	 * @return The resell price of the vehicle.
	 */
	double calculate_resell_price(double original_price, double age) {
		double price = original_price;

		if (age < 3)
			price *= 0.8;
		else if (age < 10)
			price *= 0.7;
		else
			price *= 0.5;

		return price;
	}
}
