#include <iostream>
#include "OpOverload.h"

using namespace std;

OpOverload::OpOverload() {

}

OpOverload::OpOverload(int a) {
	num = a;
}

OpOverload OpOverload::operator+(OpOverload opo) {
	OpOverload brandnew;
	brandnew.num = num + opo.num;
	return(brandnew);
}
