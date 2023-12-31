// URL: https://exercism.org/tracks/cpp/exercises/grade-school DATE: 2023-12-15

#include <map>
#include <string>
#include <vector>

#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H


namespace grade_school {
	class school {
		private:
			std::map <int, std::vector <std::string>> school_roster;
		public:
			school();
			~school();
			void add(std::string name, int grade);
			std::map <int, std::vector <std::string>> roster() const;
			std::vector <std::string> grade(int grade) const;
	};
}

#endif
