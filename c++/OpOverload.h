#ifndef OPOVERLOAD_H
#define OPOVERLOAD_H

class OpOverload {
	public:
		int num;
		OpOverload();
		OpOverload(int);
		OpOverload operator+(OpOverload);
};

#endif
