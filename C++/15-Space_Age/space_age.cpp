// URL: https://exercism.org/tracks/cpp/exercises/space-age DATE: 2023-12-08

#include "space_age.h"


space_age::space_age::space_age(long earth_seconds_age) : earth_seconds_age(earth_seconds_age) {

}

space_age::space_age::~space_age() {

}

/**
 * Returns the age in seconds.
 *
 * @return the age in seconds.
 */
long space_age::space_age::seconds() const {
	return earth_seconds_age;
}

/**
 * Calculates the age on Earth based on the number of seconds.
 *
 * @return the age on Earth in years.
 */
double space_age::space_age::on_earth() const {
	return earth_seconds_age / (60 * 60 * 24 * 365.25);
}

/**
 * Calculates the age on Mercury based on the age on Earth.
 *
 * @return the age on Mercury.
 */
double space_age::space_age::on_mercury() const {
	return on_earth() / 0.2408467;
}

/**
 * Calculates the age on Venus based on the age on Earth.
 *
 * @return the age on Venus.
 */
double space_age::space_age::on_venus() const {
	return on_earth() / 0.61519726;
}

/**
 * Calculates the age on Mars based on the age on Earth.
 *
 * @return the age on Mars.
 */
double space_age::space_age::on_mars() const {
	return on_earth() / 1.8808158;
}

/**
 * Calculates the age on Jupiter based on the age on Earth.
 *
 * @return the age on Jupiter.
 */
double space_age::space_age::on_jupiter() const {
	return on_earth() / 11.862615;

}
/**
 * Calculates the age on Saturn based on the age on Earth.
 *
 * @return the age on Saturn.
 */
double space_age::space_age::on_saturn() const {
	return on_earth() / 29.447498;
}

/**
 * Calculates the age on Uranus based on the age on Earth.
 *
 * @return the age on Uranus.
 */
double space_age::space_age::on_uranus() const {
	return on_earth() / 84.016846;
}

/**
 * Calculates the age on Neptune based on the age on Earth.
 *
 * @return the age on Neptune.
 */
double space_age::space_age::on_neptune() const {
	return on_earth() / 164.79132;
}
