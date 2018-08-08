#include <iostream>
#include <string>

using namespace std;

class MyClass {
	public:
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
	MyClass object;
	object.setName("David");
	cout << object.getName() << endl;

	return 0;
}
	
	
