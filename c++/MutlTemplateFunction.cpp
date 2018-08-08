#include <iostream>

using namespace std;

template<class F, class S> //F is First. S is Second. 

F smaller(F a, S b) {
	return (a<b ? a : b);
}


int main() {
	int x = 89;
	double y = 56.78;

	cout << smaller(x, y) << endl;
	cout << smaller(y, x) << endl;
}
