// URL: https://exercism.org/tracks/cpp/exercises/interest-is-interesting DATE: 2023-12-07

/* --------------------------------- TASK 1 --------------------------------- */

/**
 * Calculates the interest rate based on the given balance.
 *
 * @param balance The balance to calculate the interest rate for.
 * @return the interest rate corresponding to the given balance.
 */
double interest_rate(double balance) {
	if (balance < 0)
		return 3.213;
	else if (balance < 1000)
		return 0.5;
	else if (balance < 5000)
		return 1.621;
	else return
		2.475;
}

/* --------------------------------- TASK 2 --------------------------------- */

/**
 * Calculates the yearly interest for a given balance.
 *
 * @param balance The current balance.
 * @return the yearly interest calculated based on the balance.
 */
double yearly_interest(double balance) {
	return balance * interest_rate(balance) / 100.0;
}

/* --------------------------------- TASK 3 --------------------------------- */

/**
 * Calculates the updated balance after one year based on the given balance.
 * The updated balance is calculated adding the yearly interest to the balance.
 *
 * @param balance The initial balance.
 * @return the updated balance after one year.
 */
double annual_balance_update(double balance) {
	return balance + yearly_interest(balance);
}

/* --------------------------------- TASK 4 --------------------------------- */

/**
 * Calculates the number of years it takes for a balance to reach a desired
 * target balance.
 *
 * @param balance The initial balance.
 * @param target_balance The desired target balance.
 * @return the number of years it takes for the balance to reach the target balance.
 */
int years_until_desired_balance(double balance, double target_balance) {
	int year = 0;

	while (balance < target_balance) {
		balance = annual_balance_update(balance);
		year++;
	}

	return year;
}
