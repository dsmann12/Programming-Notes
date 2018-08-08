#include <iostream>
#include "Ancestor.h"
#include "Descendant.h"

using namespace std;

Descendant::Descendant() {

}

void Descendant::doSomething() {
	publicv = 1;
	protectedv = 2;

	cout << "Public variable = " <<publicv << endl;
	cout << "Protected variable = " <<protectedv << endl;	
}
