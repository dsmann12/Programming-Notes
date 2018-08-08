#include <iostream>
#include <cstdlib>
#include <vector>

//Each week has N days
//N shirts numbered 1-N
//Wears one shirt each day and only once per week
//Takes D-1 days to wash shirt, earliest day can wear it is x+D

//given first week
//given last week

//Definition
//class:			ANewHope
//Method:			count
//Parameters:		vector<int>, vector<int>, int
//Returns:			int
//method signature:	int count(vector<int> firstWeek, vector<int> lastWeek, int D)

//N can be calculated as number of elements of firstWeek

//Constraints:
//firstWeek will contain between 2 and 2500 integers inclusive
//firstWeek and lastWeek will contain same number of elements
//firstWeek and lastWeek will represent permutations of first N positive integers
//D will be between 1 and N-1 inclusive

using std::cout;
using std::endl;
using std::string;
using std::vector;

class ANewHope {
	public:
	private:
};

void printV(vector<int> &v) {
	cout << "{ ";
	for(int i : v) {
		cout << i << " ";
	}
	cout << "}\n";
}

int count(vector<int> firstWeek, vector<int> lastWeek, int D) {
	printV(firstWeek);
	printV(lastWeek);
	cout << D << endl;
	
	//shirt structure or class
	//shirt indexes are the shirt number - 1
	//bool stores whether clean or not
	//bool stores whether worn this week

	
}

int main() {
	vector<int> f {1, 2, 3, 4};
	vector<int> l {4, 3, 2, 1};
	
	count(f, l, 3);
}
