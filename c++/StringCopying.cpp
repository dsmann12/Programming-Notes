#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1("hamster.txt");
	string s2;
	string s3;

	s2 = s1; //copies string. But really copies memory location of string. 
	s3.assign(s1); //copies string1 to s3.
}
