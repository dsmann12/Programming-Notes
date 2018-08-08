#include <iostream>

using namespace std;

int main() {

	int someArray[2][5] = { 
		{0, 1, 2, 3, 4 },
		{5, 6, 7, 8, 9 }
	};

	for (int i=0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			cout << "someArray[" << i << "][" << j << "] : ";
			cout << someArray[i][j] << endl;
		}
	}

	return 0;

}