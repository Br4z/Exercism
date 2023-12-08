// URL: https://exercism.org/tracks/cpp/exercises/freelancer-rates DATE: 2023-12-07

#include <cmath>


const int billable_days = 22;

/* --------------------------------- TASK 1 --------------------------------- */

// daily_rate calculates the daily rate given an hourly rate.
double daily_rate(double hourly_rate) {
	return hourly_rate * 8;
}

/* --------------------------------- TASK 2 --------------------------------- */

// apply_discount calculates the price after a discount.
double apply_discount(double before_discount, double discount) {
	return before_discount * (1 - discount / 100);
}

/* --------------------------------- TASK 3 --------------------------------- */

// monthly_rate calculates the monthly rate, given an hourly rate and a discount.
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
	return std::ceil(apply_discount(daily_rate(hourly_rate) * billable_days, discount));
}

/* --------------------------------- TASK 4 --------------------------------- */

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount
// The returned number of days is rounded down (take the floor) to the next
// integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
	double daily_cost = apply_discount(daily_rate(hourly_rate), discount);

	return std::floor(budget / daily_cost);
}
