#include <iostream>

using namespace std;

template <class T>

class David {
	public:
		David(T x) {
			cout << x << "is not a character!\n";
		}
};

template<> //using template specialiation

class David<char> { //class specifies this handles char types
	public:
		David(char x) { //char is the data type, so use char as parameter type
			cout << x << "is indeed a character!\n";
		}
};

int main() {
	David<int> i(7);
	David<double> d(3.14);
	David<char> c('D');

}
