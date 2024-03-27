// URL: https://exercism.org/tracks/cpp/exercises/phone-number DATE: 2024-01-08

#include <stdexcept>

#include "phone_number.h"


/**
 * Cleans the given phone number by removing any non-digit characters.
 *
 * @param number The phone number to be cleaned.
 * @return the cleaned phone number as a string.
 */
std::string clean_number(std::string number) {
	std::string cleaned_number;

	for (int i = 0; i < (int) number.length(); i++)
		if (isdigit(number[i]))
			cleaned_number += number[i];

	return cleaned_number;
}

phone_number::phone_number::phone_number(std::string number) {
	std::string cleaned_number = clean_number(number);

	if (cleaned_number.length() == 11 && cleaned_number[0] == '1')
		cleaned_number = cleaned_number.substr(1);

	if (cleaned_number.size() != 10 || cleaned_number[0] < '2' || cleaned_number[3] < '2')
		throw std::domain_error("Invalid number");

	number_ = cleaned_number;
	area_code_ = cleaned_number.substr(0, 3);
}

phone_number::phone_number::~phone_number() {

}

/**
 * Returns the phone number.
 *
 * @return the phone number.
 */
std::string phone_number::phone_number::number() {
	return number_;
}

/**
 * Returns the phone number area code.
 *
 * @return the phone number area code.
 */
std::string phone_number::phone_number::area_code() {
	return area_code_;
}

phone_number::phone_number::operator std::string() const {
	std::string area_code = '(' + area_code_ + ')';
	std::string number = number_.substr(3, 3) +'-' + number_.substr(6, 4);

	return area_code + ' ' + number;
};
