#include <iostream>

using namespace std;

class Enemy {
	public:
		virtual void attack() {
			cout << "I am the enemy class!\n";
		}

};

class Ninja: public Enemy {
	public:	
		void attack() {
			cout << "Ninja attack!\n";
		}
};

class Monster: public Enemy {
	public:
		void attack() {
			cout << "Monster attack!\n";
		}	
};

class Demon: public Enemy {
	public:
};

int main() {
	Ninja n;
	Monster m;
	Demon d;

	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	Enemy *enemy3 = &d;

	enemy1->attack();
	enemy2->attack();
	enemy3->attack();

}
