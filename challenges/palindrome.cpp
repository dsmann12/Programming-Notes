#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <numeric>

using namespace std;

int main() {
	int n = 1230;
	vector<int> nums;
	while(n != 0) {
		int m = (n % 10);
		nums.push_back(m);
		n /= 10;
	}

	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	
	cout << accumulate(nums.begin(), nums.begin()+2, 0);
}
