#include <iostream>

using namespace std;

template <class T>

class David {
	T first, second;
	public:
		David(T a, T b) {
			first = a;
			second = b;
		}
		
		T bigger();
};

template <class T>

T David<T>::bigger() {
	return (first > second ? first : second);
}

int main() {
	David <int>  bo(69, 105);
	cout << bo.bigger();
}
