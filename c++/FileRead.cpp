#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream daFile("WriteFile.txt");

	int id;
	string name;
	double money;

	while(daFile >> id >> name >> money) {
		cout << id << ", " << name << ", " << money << endl;
	}
}
