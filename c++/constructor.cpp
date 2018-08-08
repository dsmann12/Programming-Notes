#include <iostream>
#include <string>

using namespace std;

class MyClass {
	public:
		MyClass() {}
		
		MyClass(string s) {
			name = s;
		}

		void setName(string s) {
			name = s;
		}

		string getName() {
			return name;
		}

	private:
		string name;
};

int main() {
	MyClass obj;
	obj.setName("David!");
	cout << "My name is " << obj.getName() << endl;

	MyClass gf("Emily!");
	cout << "My girlfriend's name is " << gf.getName() << endl;

	return 0;
}
