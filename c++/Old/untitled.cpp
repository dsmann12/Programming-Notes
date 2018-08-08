#include <iostream>

int main() {
	for (unsigned char i = 32; i < 128; i++) {
		std::cout << i;
	}

	std::cout << std::endl;

	for(int i = 32; i < 128; i++){
		std::cout << (char) i;
	}

	std::cout << std::endl;
	
	return 0;
}