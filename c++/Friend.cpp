#include <iostream>

using namespace std;

class BestFriend {
	public:	
		BestFriend() {bff = 0; }
	private:
		int bff;
	friend void stinkysFriend(BestFriend &bfo);	
};

void stinkysFriend(BestFriend &bfo) {
	bfo.bff = 99;
	cout << bfo.bff << endl;
}

int main() {
	BestFriend joe;
	stinkysFriend(joe);
}
