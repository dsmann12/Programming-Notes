#include <iostream>
#include "Sally.h"

using namespace std;

int main() {
	Sally sallyo;
	Sally *pSally = &sallyo;

	sallyo.printCrap();
	pSally->printCrap();

}
