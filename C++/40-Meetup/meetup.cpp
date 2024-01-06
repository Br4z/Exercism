// URL: https://exercism.org/tracks/cpp/exercises/meetup DATE: 2024-01-02

#include "meetup.h"


meetup::scheduler::scheduler(int month, int year) : date(boost::gregorian::date(year, month, 1)) {

}

/**
 * Calculates the date of the first occurrence of the day in a given month
 * and year, starting from a specific day of the month.
 *
 * @param year The year of the desired date.
 * @param month The month of the desired date.
 * @param start The starting day from which to begin the search.
 * @param day The desired day of the week (0 for Sunday, 1 for Monday, etc.).
 * @return The date of the first occurrence of the "day" in the month
 * "month" starting from the  "start".
 */
boost::gregorian::date meetup::scheduler::found_date(int start, int day) const {
	boost::gregorian::date date = this -> date + boost::gregorian::days(start - 1);

	while ((int) date.day_of_week() != day)
		date += boost::gregorian::days(1);

	return date;
}

/**
 * Calculates the date of the monteenth in the year and month of
 * the date in the scheduler.
 * The monteenth is defined as the first Monday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the monteenth.
 */
boost::gregorian::date meetup::scheduler::monteenth() const {
	return found_date(13, boost::gregorian::Monday);
}

/**
 * Calculates the date of the tuesteenth in the year and month of
 * the date in the scheduler.
 * The tuesteenth is defined as the first Tuesday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the tuesteenth.
 */
boost::gregorian::date meetup::scheduler::tuesteenth() const {
	return found_date(13, boost::gregorian::Tuesday);
}

/**
 * Calculates the date of the wednesteenth in the year and month of
 * the date in the scheduler.
 * The wednesteenth is defined as the first Wednesday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the wednesteenth.
 */
boost::gregorian::date meetup::scheduler::wednesteenth() const {
	return found_date(13, boost::gregorian::Wednesday);
}

/**
 * Calculates the date of the thursteenth in the year and month of
 * the date in the scheduler.
 * The thursteenth is defined as the first Thursday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the thursteenth.
 */
boost::gregorian::date meetup::scheduler::thursteenth() const {
	return found_date(13, boost::gregorian::Thursday);
}

/**
 * Calculates the date of the friteenth in the year and month of
 * the date in the scheduler.
 * The friteenth is defined as the first Friday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the friteenth.
 */
boost::gregorian::date meetup::scheduler::friteenth() const {
	return found_date(13, boost::gregorian::Friday);
}

/**
 * Calculates the date of the saturteenth in the year and month of
 * the date in the scheduler.
 * The saturteenth is defined as the first Saturday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the saturteenth.
 */
boost::gregorian::date meetup::scheduler::saturteenth() const {
	return found_date(13, boost::gregorian::Saturday);
}

/**
 * Calculates the date of the sunteenth in the year and month of
 * the date in the scheduler.
 * The sunteenth is defined as the first Saturday that end in "-teen"
 * in its ordinal enumeration.
 *
 * @return The date of the sunteenth.
 */
boost::gregorian::date meetup::scheduler::sunteenth() const {
	return found_date(13, boost::gregorian::Sunday);
}

/* -------------------------------------------------------------------------- */

/**
 * Calculates the date of the first Monday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the first Monday.
 */
boost::gregorian::date meetup::scheduler::first_monday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Monday);
}

/**
 * Calculates the date of the first Tuesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the first Tuesday.
 */
boost::gregorian::date meetup::scheduler::first_tuesday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Tuesday);
}

/**
 * Calculates the date of the first Wednesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the first Wednesday.
 */
boost::gregorian::date meetup::scheduler::first_wednesday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Wednesday);
}

/**
 * Calculates the date of the first Thursday in the year and month of
 * the date of the scheduler.
 *
 * @return The date of the first Thursday.
 */
boost::gregorian::date meetup::scheduler::first_thursday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Thursday);
}

/**
 * Calculates the date of the first Friday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the first Friday.
 */
boost::gregorian::date meetup::scheduler::first_friday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Friday);
}

/**
 * Calculates the date of the first Saturday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the first Saturday.
 */
boost::gregorian::date meetup::scheduler::first_saturday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Saturday);
}

/**
 * Calculates the date of the first Sunday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the first Sunday.
 */
boost::gregorian::date meetup::scheduler::first_sunday() const {
	return found_date(7 * 0 + 1, boost::gregorian::Sunday);
}

/* -------------------------------------------------------------------------- */

/**
 * Calculates the date of the second Monday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Monday.
 */
boost::gregorian::date meetup::scheduler::second_monday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Monday);
}

/**
 * Calculates the date of the second Tuesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Tuesday.
 */
boost::gregorian::date meetup::scheduler::second_tuesday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Tuesday);
}

/**
 * Calculates the date of the second Wednesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Wednesday.
 */
boost::gregorian::date meetup::scheduler::second_wednesday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Wednesday);
}

/**
 * Calculates the date of the second Thursday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Thursday.
 */
boost::gregorian::date meetup::scheduler::second_thursday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Thursday);
}

/**
 * Calculates the date of the second Friday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Friday.
 */
boost::gregorian::date meetup::scheduler::second_friday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Friday);
}

/**
 * Calculates the date of the second Saturday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Saturday.
 */
boost::gregorian::date meetup::scheduler::second_saturday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Saturday);
}

/**
 * Calculates the date of the second Sunday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the second Sunday.
 */
boost::gregorian::date meetup::scheduler::second_sunday() const {
	return found_date(7 * 1 + 1, boost::gregorian::Sunday);
}

/* -------------------------------------------------------------------------- */

/**
 * Calculates the date of the third Monday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Monday.
 */
boost::gregorian::date meetup::scheduler::third_monday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Monday);
}

/**
 * Calculates the date of the third Tuesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Tuesday.
 */
boost::gregorian::date meetup::scheduler::third_tuesday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Tuesday);
}

/**
 * Calculates the date of the third Wednesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Wednesday.
 */
boost::gregorian::date meetup::scheduler::third_wednesday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Wednesday);
}

/**
 * Calculates the date of the third Thursday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Thursday.
 */
boost::gregorian::date meetup::scheduler::third_thursday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Thursday);
}

/**
 * Calculates the date of the third Friday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Friday.
 */
boost::gregorian::date meetup::scheduler::third_friday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Friday);
}

/**
 * Calculates the date of the third Saturday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Saturday.
 */
boost::gregorian::date meetup::scheduler::third_saturday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Saturday);
}

/**
 * Calculates the date of the third Sunday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the third Sunday.
 */
boost::gregorian::date meetup::scheduler::third_sunday() const {
	return found_date(7 * 2 + 1, boost::gregorian::Sunday);
}

/* -------------------------------------------------------------------------- */

/**
 * Calculates the date of the fourth Monday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Monday.
 */
boost::gregorian::date meetup::scheduler::fourth_monday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Monday);
}

/**
 * Calculates the date of the fourth Tuesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Tuesday.
 */
boost::gregorian::date meetup::scheduler::fourth_tuesday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Tuesday);
}

/**
 * Calculates the date of the fourth Wednesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Wednesday.
 */
boost::gregorian::date meetup::scheduler::fourth_wednesday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Wednesday);
}

/**
 * Calculates the date of the fourth Thursday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Thursday.
 */
boost::gregorian::date meetup::scheduler::fourth_thursday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Thursday);
}

/**
 * Calculates the date of the fourth Friday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Friday.
 */
boost::gregorian::date meetup::scheduler::fourth_friday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Friday);
}

/**
 * Calculates the date of the fourth Saturday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Saturday.
 */
boost::gregorian::date meetup::scheduler::fourth_saturday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Saturday);
}

/**
 * Calculates the date of the fourth Sunday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the fourth Sunday.
 */
boost::gregorian::date meetup::scheduler::fourth_sunday() const {
	return found_date(7 * 3 + 1, boost::gregorian::Sunday);
}

/* -------------------------------------------------------------------------- */

/**
 * Calculates the date of the last Monday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Monday.
 */
boost::gregorian::date meetup::scheduler::last_monday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Monday);
}

/**
 * Calculates the date of the last Tuesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Tuesday.
 */
boost::gregorian::date meetup::scheduler::last_tuesday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Tuesday);
}

/**
 * Calculates the date of the last Wednesday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Wednesday.
 */
boost::gregorian::date meetup::scheduler::last_wednesday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Wednesday);
}

/**
 * Calculates the date of the last Thursday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Thursday.
 */
boost::gregorian::date meetup::scheduler::last_thursday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Thursday);
}

/**
 * Calculates the date of the last Friday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Friday.
 */
boost::gregorian::date meetup::scheduler::last_friday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Friday);
}

/**
 * Calculates the date of the last Saturday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Saturday.
 */
boost::gregorian::date meetup::scheduler::last_saturday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Saturday);
}

/**
 * Calculates the date of the last Sunday in the year and month of
 * the date in the scheduler.
 *
 * @return The date of the last Sunday.
 */
boost::gregorian::date meetup::scheduler::last_sunday() const {
	return found_date(date.end_of_month().day() - 7 + 1, boost::gregorian::Sunday);
}
