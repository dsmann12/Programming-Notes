#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "Birthday.h"
using namespace std;

class People {
	public:
		People(string x, Birthday bo);
		void printinfo();
	private:
		string name;
		Birthday dateofbirth;
	protected:
};

#endif
