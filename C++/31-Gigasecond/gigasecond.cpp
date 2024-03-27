// URL: https://exercism.org/tracks/cpp/exercises/gigasecond DATE: 2023-12-26

#include "gigasecond.h"


/**
 * Determines the date and time one gigasecond after a certain date.
 * A gigasecond is one thousand million seconds.
 *
 * @param ptime The input date.
 * @return the time one gigasecond after the given time.
 */
boost::posix_time::ptime gigasecond::advance(boost::posix_time::ptime time) {
	return time + boost::posix_time::seconds(1000000000);
}
