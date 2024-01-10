// URL: https://exercism.org/tracks/cpp/exercises/complex-numbers DATE: 2024-01-10

#ifndef COMPLEX_NUMBERS_H
#define COMPLEX_NUMBERS_H


namespace complex_numbers {
	class Complex {
		private:
			float a;
			float b;
		public:
			Complex(float a, float b);
			~Complex();

			float real() const;
			float imag() const;

			Complex conj() const;
			float abs() const;

			Complex operator +(const Complex& other) const;
			Complex operator -(const Complex& other) const;

			Complex operator *(const Complex& other) const;
			Complex operator /(const Complex& other) const;

			Complex exp() const;
	};
}

#endif
