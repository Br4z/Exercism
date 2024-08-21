# URL: https://exercism.org/tracks/python/exercises/currency-exchange

# ---------------------------------- TASK 1 ---------------------------------- #

def exchange_money(budget, exchange_rate):
	"""Calculate the value of the exchanged currency.

	:param budget: float - amount of money you are planning to exchange.
	:param exchange_rate: float - unit value of the foreign currency.
	:return: float - exchanged value of the foreign currency you can receive.
	"""

	return budget / exchange_rate

# ---------------------------------- TASK 2 ---------------------------------- #

def get_change(budget, exchanging_value):
	"""Calculate the amount of money that is left from the budget.

	:param budget: float - amount of money you own.
	:param exchanging_value: float - amount of your money you want to exchange now.
	:return: float - amount left of your starting currency after exchanging.
	"""

	return budget - exchanging_value

# ---------------------------------- TASK 3 ---------------------------------- #

def get_value_of_bills(denomination, number_of_bills):
	"""Calculate the total value of the bills

	:param denomination: int - the value of a bill.
	:param number_of_bills: int - total number of bills.
	:return: int - calculated value of the bills.
	"""

	return denomination * number_of_bills

# ---------------------------------- TASK 4 ---------------------------------- #

def get_number_of_bills(amount, denomination):
	"""Calculate the number of currency bills that you can receive within
	the given amount.

	:param amount: float - the total starting value.
	:param denomination: int - the value of a single bill.
	:return: int - number of bills that can be obtained from the amount.
	"""

	return amount // denomination

# ---------------------------------- TASK 5 ---------------------------------- #

def get_leftover_of_bills(amount, denomination):
	"""Calculate the leftover amount that cannot be returned from your starting
	amount given the denomination of bills.

	:param amount: float - the total starting value.
	:param denomination: int - the value of a single bill.
	:return: float - the amount that is "leftover", given the current denomination.
	"""

	return amount % denomination

# ---------------------------------- TASK 6 ---------------------------------- #

def exchangeable_value(budget, exchange_rate, spread, denomination):
	"""Calculate the maximum value of the new currency after calculating the
	exchange rate plus the spread.

	:param budget: float - the amount of your money you are planning to exchange.
	:param exchange_rate: float - the unit value of the foreign currency.
	:param spread: int - percentage that is taken as an exchange fee.
	:param denomination: int - the value of a single bill.
	:return: int - maximum value you can get.
	"""

	new_exchange_rate = exchange_rate * (1 + spread / 100)
	exchanged_budget = exchange_money(budget, new_exchange_rate)

	return get_value_of_bills(denomination, get_number_of_bills(exchanged_budget, denomination))
