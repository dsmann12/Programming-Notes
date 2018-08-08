#include <iostream>

using namespace std;

int main() {
	string previous = ""; //initialized to "not a word"
	string current;
	while (cin >> current) { //read a stream of words
		if(previous == current) { //check if word same as last
			cout << "Reapeated word: " << current << endl;
		}
		previous = current;
	}
}
