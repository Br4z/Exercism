// URL: https://exercism.org/tracks/cpp/exercises/clock DATE: 2024-01-01

#include <string>

#ifndef CLOCK_H
#define CLOCK_H

namespace date_independent {
	class clock {
		private:

		public:

			int hour{ 0 };
			int minute{ 0 };

			clock(int hour, int minute);

			static clock at(int hour, int minute);
			clock plus(int minutes);

			operator std::string() const;
			bool operator == (const clock& c) const;
			bool operator != (const clock& c) const;
	};
}

#endif
