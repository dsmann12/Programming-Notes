#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "My name is David";
	cout << s1.substr(11, 17) << endl;

	string one("apples ");
	string two("beans ");

	cout << one << two << endl;
	one.swap(two);
	cout << one << two << endl;

	string s2 = "ham is spam oh yes i am";
	cout << s2.find("am") << endl;
	cout << s2.rfind("am") << endl;

	string s3 = "Hi my name is david and I love bacon and ham!";
	cout << s3 << endl;
	s3.erase(20);
	cout << s3 << endl;

	s3 = "Hi my name is david and I love bacon and ham!";
	s3.replace(14, 5, "David Scheuermann");
	cout << s3 << endl; 	

	s3.insert(14, "awesome ");
	cout << s3 << endl;
	
}
