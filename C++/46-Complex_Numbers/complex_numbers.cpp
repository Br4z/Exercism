// URL: https://exercism.org/tracks/cpp/exercises/complex-numbers DATE: 2024-01-10

#include <cmath>

#include "complex_numbers.h"


complex_numbers::Complex::Complex(float a, float b) : a(a), b(b) {

}

complex_numbers::Complex::~Complex() {

}

/**
 * Returns the real part of the complex number.
 *
 * @return the real part of the complex number.
 */
float complex_numbers::Complex::real() const {
	return a;
}

/**
 * Returns the imaginary part of the complex number.
 *
 * @return the imaginary part of the complex number.
 */
float complex_numbers::Complex::imag() const {
	return b;
}

/**
 * Calculates the complex conjugate of the current complex number.
 *
 * @return the complex conjugate of the current complex number.
 */
complex_numbers::Complex complex_numbers::Complex::conj() const {
	return Complex{ a, -b };
}

/**
 * Calculates the absolute value (magnitude) of the complex number.
 *
 * @return the absolute value of the complex number.
 */
float complex_numbers::Complex::abs() const {
	return sqrt(pow(a, 2) + pow(b, 2));
}

/**
 * Overloaded addition operator for complex numbers.
 *
 *
 * @param other The complex number to add.
 * @return the sum of the two complex numbers.
 */
complex_numbers::Complex complex_numbers::Complex::operator +(const Complex &other) const {
	return Complex{ a + other.real(), b + other.imag() };
}

/**
 * Overloaded subtraction operator for complex numbers.
 *
 *
 * @param other The complex number to subtract.
 * @return the difference between the two complex numbers.
 */
complex_numbers::Complex complex_numbers::Complex::operator -(const Complex &other) const {
	return Complex{ a - other.real(), b - other.imag() };
}

/**
 * Overloaded multiplication operator for complex numbers.
 *
 * (a + b * i) * (c + d * i) = (a * c - b * d) + (a * d + b * c) * i.
 *
 * @param other The complex number to multiply with.
 * @return the product of the two complex numbers.
 */
complex_numbers::Complex complex_numbers::Complex::operator *(const Complex &other) const {
	return Complex{ a * other.real() - b * other.imag(), b * other.real() + a * other.imag() };
}

/**
 * Overloaded division operator for complex numbers.
 *
 * (a + i * b) / (c + i * d) = (a * c + b * d) / (c^2 + d^2) +
 * 	(b * c - a * d) / (c^2 + d^2) * i
 *
 * @param other The complex number to divide by.
 * @return the quotient of the division.
 */
complex_numbers::Complex complex_numbers::Complex::operator /(const Complex &other) const {
	float real = (a * other.real() + b * other.imag()) / (pow(other.real(), 2) + pow(other.imag(), 2));
	float imaginary = (b * other.real() - a * other.imag()) / (pow(other.real(), 2) + pow(other.imag(), 2));

	return Complex{ real, imaginary };
}

/**
 * Calculates the exponential of the complex number using Euler's formula.
 *
 * e^(a + i * b) = e^a * e^(i * b) = e^a * (cos(b) + i * sin(b))
 *
 * @return the exponential of the complex number.
 */
complex_numbers::Complex complex_numbers::Complex::exp() const {
	float e = std::exp(1.0);

	float real = pow(e, a) * cos(b);
	float imaginary = pow(e, a) * sin(b);

	return Complex{ real, imaginary }; //
}
