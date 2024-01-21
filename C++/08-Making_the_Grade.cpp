// URL: https://exercism.org/tracks/cpp/exercises/making-the-grade DATE: 2023-12-07

#include <array>
#include <string>
#include <vector>


/* --------------------------------- TASK 1 --------------------------------- */

/**
 * Rounds down each element in a vector of double scores and returns a vector
 * of truncated integer scores.
 *
 * @param student_scores The vector of double scores to be rounded down.
 * @return The vector of truncated integer scores.
 */
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

/**
 * Counts the number of failed students based on their scores.
 * A student is considered failed if their score is less than or equal to 40.
 *
 * @param student_scores The vector containing the scores of all students.
 * @return The number of failed students.
 */
int count_failed_students(std::vector <int> student_scores) {
	int failed_students{ 0 };

	for (int i = 0; i < student_scores.size(); i++)
		if (student_scores[i] <= 40)
			failed_students++;

	return failed_students;
}

/* --------------------------------- TASK 3 --------------------------------- */

/**
 * Determines the students were "the best" based on the provided threshold and
 * their scores.
 *
 * @param student_scores The vector of student scores.
 * @param threshold The threshold value to filter the scores.
 * @return A vector containing scores that are above or equal to the threshold.
 */

std::vector <int> above_threshold(std::vector <int> student_scores, int threshold) {
	std::vector <int> filtered_scores;

	for (int i = 0; i < student_scores.size(); i++) {
		int score = student_scores[i];

		if (score >= threshold)
			filtered_scores.emplace_back(score);
	}

	return filtered_scores;
}

/* --------------------------------- TASK 4 --------------------------------- */

/**
 * Creates a list of grade thresholds based on the provided highest grade.
 *
 * @param highest_score The highest score in the class.
 * @return A vector containing the grade thresholds.
 */
std::array <int, 4> letter_grades(int highest_score) {
	int interval = (highest_score - 40) / 4;

	int D = 41;
	int C = D + interval;
	int B = C + interval;
	int A = B + interval;

	return std::array <int, 4> { D, C, B, A };
}

/* --------------------------------- TASK 5 --------------------------------- */

/**
 * Organizes the student's rank, name, and grade information in ascending order.
 *
 * @param student_scores The vector containing the scores of all students.
 * @param student_names The vector containing the names of all students.
 * @return A vector containing the student's rank, name, and grade information
 */
std::vector <std::string> student_ranking(std::vector <int> student_scores, std::vector <std::string> student_names) {
	std::vector <std::string> ranking;

	for (int i = 0; i < student_scores.size(); i++) {
		std::string student = std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]);

		ranking.emplace_back(student);
	}

	return ranking;
}

/* --------------------------------- TASK 6 --------------------------------- */

/**
 * Finds the student with a perfect score.
 *
 * @param student_scores A vector containing the scores of the students.
 * @param student_names A vector containing the names of the students.
 * @return The name of the student with a perfect score, or an empty string if
 * no student has a perfect score.
 */
std::string perfect_score(std::vector <int> student_scores, std::vector <std::string> student_names) {
	std::string best_student;

	for (int i = 0; i < student_scores.size(); i++)
		if (student_scores[i] == 100) { best_student = student_names[i]; break; }

	return best_student;
}
