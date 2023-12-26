// URL: https://exercism.org/tracks/cpp/exercises/gigasecond DATE: 2023-12-26

#include "boost/date_time/posix_time/posix_time.hpp"

#ifndef GIGASECOND_H
#define GIGASECOND_H


namespace gigasecond {
	boost::posix_time::ptime advance(boost::posix_time::ptime time);
}

#endif
