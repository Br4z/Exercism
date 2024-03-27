// URL: https://exercism.org/tracks/cpp/exercises/space-age DATE: 2023-12-08

#ifndef SPACE_AGE_H
#define SPACE_AGE_H


namespace space_age {
	class space_age {
		private:
			long earth_seconds_age;

		public:
			space_age(long earth_seconds_age);
			~space_age();
			long seconds() const;
			double on_earth() const;
			double on_mercury() const;
			double on_venus() const;
			double on_mars() const;
			double on_jupiter() const;
			double on_saturn() const;
			double on_uranus() const;
			double on_neptune() const;
	};
}

#endif
