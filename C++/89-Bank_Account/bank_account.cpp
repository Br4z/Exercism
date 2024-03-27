// URL: https://exercism.org/tracks/cpp/exercises/bank-account DATE: 2024-02-23

#include <stdexcept>

#include "bank_account.h"


/**
 * Opens the bank account.
 *
 * If the account is already open, it throws an error.
 */
void bank_account::BankAccount::open() {
	if (is_open)
		throw std::runtime_error("Opening an account already opened");

	is_open = true;
}

/**
 * Closes the bank account.
 *
 * If the account is already closed, it throws an error.
 */
void bank_account::BankAccount::close() {
	if (!is_open)
		throw std::runtime_error("Closing an already closed account");

	actual_balance = 0;
	is_open = false;
}

/**
 * Retrieves the balance of the bank account.
 *
 * @return the current balance of the account.
 * @throws std::runtime_error If the account is closed, it throws an error.
 */
int bank_account::BankAccount::balance() {
	if (!is_open)
		throw std::runtime_error("Checking the balance of a closed account");

	return actual_balance;
}

/**
 * Deposits money into the bank account.
 *
 * @param amount The amount to be deposited.
 * @throws std::runtime_error If the account is closed, it throws an error.
 * @throws std::runtime_error If the deposited amount is negative, it throws an error.
 */
void bank_account::BankAccount::deposit(int amount) {
	std::lock_guard lock_guard(mutex);

	if (!is_open)
		throw std::runtime_error("Depositing in a closed account");

	if (amount < 0)
		throw std::runtime_error("Depositing a negative amount");

	actual_balance += amount;
}

/**
 * Withdraws money from the bank account.
 *
 * @param amount The amount to be withdrawn.
 * @throws std::runtime_error If the account is closed, it throws an error.
 * @throws std::runtime_error If the withdrawal amount exceeds the available balance, it throws an error.
 * @throws std::runtime_error If the withdrawal amount is negative, it throws an error.
 */
void bank_account::BankAccount::withdraw(int amount) {
	std::lock_guard lock_guard(mutex);

	if (!is_open)
		throw std::runtime_error("Withdrawing from a closed account");

	if (amount > actual_balance)
		throw std::runtime_error("Withdrawal exceeds available balance");

	if (amount < 0)
		throw std::runtime_error("Withdrawing a negative amount");

	actual_balance -= amount;
}
