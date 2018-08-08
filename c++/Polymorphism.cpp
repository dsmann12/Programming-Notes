#include <iostream>

using namespace std;

class Enemy {
	protected:
		int attackPower;
	public:
		void setAttackPower(int n) {
			attackPower = n;
		}
};

class Ninja: public Enemy {
	public:	
		void attack() {
			cout << "I am a ninja! Ninja chop! - ";
			cout << attackPower << endl;
		}
};

class Monster: public Enemy {
	public:
		void attack() {
			cout << "Monster must eat you!!! - ";
			cout << attackPower << endl;
		}	
};

int main() {
	Ninja n;
	Monster m;

	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	
	enemy1->setAttackPower(29);
	enemy2->setAttackPower(99);

	n.attack();
	m.attack();

}
