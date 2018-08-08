#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
	int y = 1905;
	int x = log10(y);
	int z = y/(pow(10, x-1));
	cout << x << endl;
	cout << z << endl;
}
