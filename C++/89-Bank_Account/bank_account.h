// URL: https://exercism.org/tracks/cpp/exercises/bank-account DATE: 2024-02-23

#include <mutex>

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


namespace bank_account {
	class BankAccount {
		private:
			std::mutex mutex;
			bool is_open = false;
			int actual_balance = 0;
		public:
			void open();
			void close();
			int balance();
			void deposit(int amount);
			void withdraw(int amount);
	};

}

#endif
