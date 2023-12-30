// URL: https://exercism.org/tracks/cpp/exercises/leap DATE: 2023-12-08

namespace leap {
	/**
	 * Determines if a given year is a leap year.
	 *
	 * @param year The year to be checked.
	 * @return True if the year is a leap year, false otherwise.
	 */
	bool is_leap_year(int year) {
		if (year % 4 == 0) {
			if (year % 100 == 0)
				return year % 400 == 0;
			else
				return true;
		} else
			return false;

		// return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	}
}
