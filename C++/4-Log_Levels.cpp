// URL: https://exercism.org/tracks/cpp/exercises/log-levels DATE: 2023-12-07

#include <string>


namespace log_line {
	/* --------------------------------- TASK 1 --------------------------------- */

	/**
	 * Returns the message part of a log line.
	 *
	 * @param log The log line to extract the message from.
	 * @return std::string The message part of the log line.
	 */
	std::string message(std::string log) {
		return log.substr(log.find(':') + 2);
	}

	/* --------------------------------- TASK 2 --------------------------------- */

	/**
	 * Returns the log level of a log line.
	 *
	 * @param log The log line to extract the log level from.
	 * @return std::string The log level of the log line.
	 */
	std::string log_level(std::string log) {
		return log.substr(1, log.find(']') - 1);
	}

	/* --------------------------------- TASK 3 --------------------------------- */

	/**
	 * Reformats a log line to include the message and log level.
	 *
	 * @param log The log line to reformat.
	 * @return std::string The reformatted log line.
	 */
	std::string reformat(std::string log) {
		return message(log) + " (" + log_level(log) + ")";
	}
}
