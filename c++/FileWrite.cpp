#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream daFile("WriteFile.txt");
	
	cout << "Enter player ID, name, and money!\n";
	cout << "Press CTRL-Z to exit\n";

	int id;
	string name;
	double money;

	while(cin >> id >> name >> money) {
		daFile << id << " " << name << " " << money << endl;
	}

}
