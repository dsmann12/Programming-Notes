#include <iostream>
#include <fstream>

using namespace std;

int main() {
//	ofstream davidFile; //object for file
//	davidFile.open("input.txt"); //string is file path. Creats if doesn't exist

	ofstream davidFile("input.txt");
	
	davidFile << "This is file input\n";

	davidFile.close();
	
}
