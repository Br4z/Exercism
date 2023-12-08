// URL: https://exercism.org/tracks/cpp/exercises/making-the-grade DATE: 2023-12-07

#include <array>
#include <string>
#include <vector>


/* --------------------------------- TASK 1 --------------------------------- */

// Round down all provided student scores.
std::vector <int> round_down_scores(std::vector <double> student_scores) {
	std::vector <int> truncated_scores;

	while (!student_scores.empty()) {
		int truncatedGrade = student_scores.front();

		truncated_scores.emplace_back(truncatedGrade);
		student_scores.erase(student_scores.begin());
	}

	return truncated_scores;
}

/* --------------------------------- TASK 2 --------------------------------- */

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector <int> student_scores) {
	int failed_students{0};

	for (int i = 0; i < student_scores.size(); i++) {
		if (student_scores[i] <= 40) failed_students++;
	}

	return failed_students;
}

/* --------------------------------- TASK 3 --------------------------------- */

// Determine how many of the provided student scores were 'the best' based on the provided threshold.
std::vector <int> above_threshold(std::vector<int> student_scores, int threshold) {
	std::vector <int> filtered_scores;

	for (int i = 0; i < student_scores.size(); i++) {
		int score = student_scores[i];

		if (score >= threshold) filtered_scores.emplace_back(score);
	}

	return filtered_scores;
}

/* --------------------------------- TASK 4 --------------------------------- */

// Create a list of grade thresholds based on the provided highest grade.
std::array <int, 4> letter_grades(int highest_score) {
	int interval = (highest_score - 40) / 4;

	int D = 41;
	int C = D + interval;
	int B = C + interval;
	int A = B + interval;

	return std::array <int, 4> { D, C, B, A };
}

/* --------------------------------- TASK 5 --------------------------------- */

// Organize the student's rank, name, and grade information in ascending order.
std::vector <std::string> student_ranking(std::vector <int> student_scores, std::vector <std::string> student_names) {
	std::vector <std::string> ranking;

	for (int i = 0; i < student_scores.size(); i++) {
		std::string student = std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);

		ranking.emplace_back(student);
	}

	return ranking;
}

/* --------------------------------- TASK 6 --------------------------------- */

// Create a string that contains the name of the first student to make a perfect score on the exam.
std::string perfect_score(std::vector <int> student_scores, std::vector <std::string> student_names) {
	std::string best_student = "";

	for (int i = 0; i < student_scores.size(); i++) {
		if (student_scores[i] == 100) { best_student = student_names[i]; break; }
	}

	return best_student;
}
