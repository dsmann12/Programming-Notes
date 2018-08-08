#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

int main() {
	int a[10];
	for(int i = 0; i < 10; i++) {
		a[i] = std::rand() % 10; 
	}

	cout << "[" << a[0];
	for(int i = 1; i < 10; i++) {
		cout << ", " << a[i];
	}
	cout << endl;

	for(int i = 1; i < 10; i++) {
		int cur = i;
		for(int j = i - 1; j >= 0; j--) {
			if (a[cur] < a[j]) {
				int temp = a[cur];
				a[cur] = a[j];
				a[j] = temp;
				cur = j;
			};
		}
	}	

	cout << "[" << a[0];
	for(int i = 1; i < 10; i++) {
		cout << ", " << a[i];
	}
	cout << "]" << endl;
}
