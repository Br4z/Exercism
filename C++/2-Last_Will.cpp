
// URL: https://exercism.org/tracks/cpp/exercises/last-will DATE: 2023-12-07

// Secret knowledge of the Zhang family
namespace zhang {
	int bank_number_part(int secret_modifier) {
		int zhang_part{8'541};
		return (zhang_part * secret_modifier) % 10000;
	}

	namespace red {
		int code_fragment() { return 512; }
	}

	namespace blue {
		int code_fragment() { return 677; }
	}
}

// Secret knowledge of the Khan family
namespace khan {
	int bank_number_part(int secret_modifier) {
		int khan_part{4'142};
		return (khan_part*secret_modifier) % 10000;
	}

	namespace red {
		int code_fragment() {return 148;}
	}

	namespace blue {
		int code_fragment() {return 875;}
	}
}

// Secret knowledge of the Garcia family
namespace garcia {
	int bank_number_part(int secret_modifier) {
		int garcia_part{4'023};
		return (garcia_part * secret_modifier) % 10000;
	}

	namespace red {
		int code_fragment() { return 118; }
	}

	namespace blue {
		int code_fragment() { return 923; }
	}
}

namespace estate_executor {
	/**
	 * Calculates the assembled account number adding the bank_number_part from each of the three families. Using
	 * the secret_modifier to reveal the secret account number.
	 *
	 * @param secret_modifier The secret modifier key to reveal the secret account number.
	 * @return The assembled account number as an int.
	 */
	int assemble_account_number(int secret_modifier) {
		int zhang_part = zhang::bank_number_part(secret_modifier);
		int khan_part = khan::bank_number_part(secret_modifier);
		int garcia_part = garcia::bank_number_part(secret_modifier);

		return zhang_part + khan_part + garcia_part;
	}

	/**
	 * Calculates the resulting code by combining the fragments from the three families to a single integer.
	 *
	 * @return The assembled code as an int.
	 */
	int assemble_code() {
		int red_fragment = zhang::red::code_fragment() + khan::red::code_fragment() + garcia::red::code_fragment();
		int blue_fragment = zhang::blue::code_fragment() + khan::blue::code_fragment() + garcia::blue::code_fragment();

		return red_fragment * blue_fragment;
	}
}
