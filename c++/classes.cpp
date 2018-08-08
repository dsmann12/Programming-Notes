#include <iostream>

using namespace std;

class MyClass {
	public:
		int n;
		char name[10];
		
		void sayit() {
			cout << "David rules!\n";
		}
};

int main() {
	MyClass object;
	object.sayit();

	return 0;
}
