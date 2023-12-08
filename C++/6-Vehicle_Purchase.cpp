// URL: https://exercism.org/tracks/cpp/exercises/vehicle-purchase DATE: 2023-12-07

#include <string>


namespace vehicle_purchase {
	/* --------------------------------- TASK 1 --------------------------------- */

	// needs_license determines whether a license is needed to drive a type of
	// vehicle. Only "car" and "truck" require a license.
	bool needs_license(std::string kind){
		return kind == "car" or kind == "truck";
	}

	/* --------------------------------- TASK 2 --------------------------------- */

	// choose_vehicle recommends a vehicle for selection. It always recommends the
	// vehicle that comes first in lexicographical order.
	std::string choose_vehicle(std::string option1, std::string option2) {
		std::string betterOption;

		if (option2 > option1) betterOption = option1;
		else betterOption = option2;

		return betterOption + " is clearly the better choice.";
	}

	/* --------------------------------- TASK 3 --------------------------------- */

	// calculate_resell_price calculates how much a vehicle can resell for at a
	// certain age.
	double calculate_resell_price(double original_price, double age) {
		double price = original_price;

		if (age < 3) price *= 0.8;
		else if (age < 10) price *= 0.7;
		else price *= 0.5;

		return price;
	}
}
