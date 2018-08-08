#include<iostream>

using namespace std;

int main() {
	try {
		int parentsAge = 30;
		int sonsAge = 34;

		if (sonsAge > parentsAge) {
			throw 99;
		}
	}
	catch(int x) {
		cout << "son cannot be older than mom, ERROR NUMBER: " << x << endl;
	}
}
