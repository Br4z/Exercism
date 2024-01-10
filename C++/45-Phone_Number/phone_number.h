// URL: https://exercism.org/tracks/cpp/exercises/phone-number DATE: 2024-01-08

#include <string>

#ifndef PHONE_NUMBER_H
#define PHONE_NUMBER_H


namespace phone_number {
	class phone_number {
		private:
			std::string number_;
			std::string area_code_;

		public:
		phone_number(std::string number);
		~phone_number();

		std::string number();
		std::string area_code();

		operator std::string() const;
	};
}

#endif
