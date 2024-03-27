// URL: https://exercism.org/tracks/cpp/exercises/robot-name DATE: 2023-12-27

#include <string>
#include <unordered_set>

#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H


namespace robot_name {
	class robot {
		private:
			std::string robot_name;
			static std::unordered_set <std::string> existing_names;

			void assign_name();
		public:
			robot();
			~robot();

			std::string name() const;
			void reset();
	};
}

#endif
