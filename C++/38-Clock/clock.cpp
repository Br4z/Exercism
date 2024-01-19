// URL: https://exercism.org/tracks/cpp/exercises/clock DATE: 2024-01-01

#include "clock.h"


date_independent::clock::clock(int hour, int minute) {
	int clock_minute = minute % 60;
	int clock_hour = ((minute / 60) + hour % 24) % 24;

	if (clock_minute < 0) {
		clock_hour--;
		clock_minute += 60;
	}

	if (clock_hour < 0)
		clock_hour += 24;

	this -> hour = clock_hour;
	this -> minute = clock_minute;
}

/**
 * Creates a new instance of the clock class with the specified hour
 * and minute.
 *
 * @param hour The hour value of the clock.
 * @param minute The minute value of the clock.
 * @return The newly created clock instance.
 */
date_independent::clock date_independent::clock::at(int hour, int minute) {
	return clock(hour, minute);
}

/**
 * Creates a new instance of the clock class by adding the minutes to
 * the clock from which the method is called.
 *
 * @param minutes The amount of minutes to be added to the clock.
 * @return The newly created clock instance.
 */
date_independent::clock date_independent::clock::plus(int minutes) {
	return clock(hour, minute + minutes);
}

date_independent::clock::operator std::string() const {
	std::string result;

	return (hour > 9 ? "" : "0") + std::to_string(hour) + ':' +
		(minute > 9 ? "" : "0") + std::to_string(minute);
}

bool date_independent::clock::operator == (const clock& clock) const {
	return hour == clock.hour && minute == clock.minute;
}

bool date_independent::clock::operator != (const clock& clock) const {
	return !(*this == clock);
}
