#include <iostream>

int main() {

	enum WeekDays { Sun, Mon, Tue, Wed, Thu, Fri, Sat, DaysInWeek };
	int arrayWeek[DaysInWeek] = { 10, 20, 30, 40, 50, 60, 70 };

	std::cout << "the value at Tuesday is: " << arrayWeek[Tue] << std::endl;

	return 0;
}