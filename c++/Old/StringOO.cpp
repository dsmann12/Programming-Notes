#include <iostream>
#include <string>

using namespace std;

int main() {

	string str1 ("This is a C++ string!");

	cout << "str1 = " << str1 << endl;

	string str2;

	str2 = str1;

	cout << "Result of assignment, str2 = " << str2 << endl;

	str2 = "Hello World!";

	cout << "After overwriting contents, str2 = " << str2 << endl;
	cout << endl << endl;

	string strAddResult;

	strAddResult = str1 + str2;

	cout << "The result of str1 + str2 is = " << strAddResult << endl;

	string str3 = "Example 3";

	cout << str3 << endl;

	return 0;
}
