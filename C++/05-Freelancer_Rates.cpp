// URL: https://exercism.org/tracks/cpp/exercises/freelancer-rates DATE: 2023-12-07

#include <cmath>


const int billable_days = 22;

/* --------------------------------- TASK 1 --------------------------------- */

/**
 * Calculates the daily rate based on the given hourly rate.
 *
 * @param hourly_rate The hourly rate of the freelancer.
 * @return the calculated daily rate.
 */
double daily_rate(double hourly_rate) {
	return hourly_rate * 8;
}

/* --------------------------------- TASK 2 --------------------------------- */

/**
 * Applies a discount to a given amount.
 *
 * @param before_discount The original amount before the discount.
 * @param discount The discount percentage to be applied.
 * @return the amount after applying the discount.
 */
double apply_discount(double before_discount, double discount) {
	return before_discount * (1 - discount / 100);
}

/* --------------------------------- TASK 3 --------------------------------- */

/**
 * Calculates the monthly rate for a freelancer based on the hourly rate and discount.
 *
 * @param hourly_rate The hourly rate of the freelancer.
 * @param discount The discount to be applied to the monthly rate.
 * @return the calculated monthly rate.
 */
int monthly_rate(double hourly_rate, double discount) {
	return std::ceil(apply_discount(daily_rate(hourly_rate) * billable_days, discount));
}

/* --------------------------------- TASK 4 --------------------------------- */

/**
 * Calculates the number of days within the given budget, taking into account
 * the hourly rate and discount.
 *
 * @param budget The total budget available.
 * @param hourly_rate The hourly rate of the freelancer.
 * @param discount The discount to be applied to the daily cost.
 * @return the number of days within the budget.
 */
int days_in_budget(int budget, double hourly_rate, double discount) {
	double daily_cost = apply_discount(daily_rate(hourly_rate), discount);

	return std::floor(budget / daily_cost);
}
