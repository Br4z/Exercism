// URL: https://exercism.org/tracks/cpp/exercises/allergies DATE: 2023-12-29

#include "allergies.h"


const std::string allergies_list[] = {
	"eggs", // 2^0 = 00000001
	"peanuts", // 2^1 = 00000010
	"shellfish", // 2^2 = 00000100
	"strawberries", // 2^3 = 00001000
	"tomatoes", // 2^4 = 00010000
	"chocolate", // 2^5 = 00100000
	"pollen", // 2^6 = 01000000
	"cats" // 2^7 = 10000000
};

allergies::allergy_test::allergy_test(int score) : score(score) {
	int allergies_size = sizeof(allergies_list) / sizeof(allergies_list[0]);

	for (int i = 0; i < allergies_size; i++)
		if ((1 << i) & score)
			allergies.emplace(allergies_list[i]);
}

allergies::allergy_test::~allergy_test() {

}

/**
 * Checks if the person is allergic to a specific allergy .
 *
 * @param allergy The allergy to check.
 * @return True if the person is allergic to the allergy, false otherwise.
 */
bool allergies::allergy_test::is_allergic_to(std::string allergy) {
	return allergies.find(allergy) != allergies.end();
}

/**
 * Returns the set of allergies.
 *
 * @return The set of allergies.
 */
std::unordered_set <std::string> allergies::allergy_test::get_allergies() {
	return allergies;
}
