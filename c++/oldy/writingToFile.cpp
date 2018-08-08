#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

using std::cout;
using std::endl;
using std::fstream;
using std::ofstream;

int main() {
	ofstream fs("numbers.txt");
	if (!fs) {
		cout << "File Not Created!\n";
		return 1;
	}
	srand(time(NULL));

	for(int i = 0; i < 10; i++) {
		fs << rand() % 100 << endl;
	}

	fs.close();
}
