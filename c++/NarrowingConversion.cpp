#include <iostream>

using namespace std;

int main() {
	double d = 0;
	while(cin>>d) {
		int i = d;
		char c = i;
		int i2 = c;
		cout << "d == " << d << endl;
		cout << "i == " << i << endl;
		cout << "i2 == " << i2 << endl;
		cout << "char(" << c << ")\n";
	}
}
