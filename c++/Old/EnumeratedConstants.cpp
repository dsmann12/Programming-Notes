#include <iostream>

int main() {

	enum Days { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

	Days today;
	today = MONDAY;

	if (today == SATURDAY || today == SUNDAY) {
		std::cout << "\nGotta love the weekends!\n";
	}
	else {
		std::cout <<"\nBack to work.\n";
	}

	return 0;
}