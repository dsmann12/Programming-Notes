#include <iostream>
#include <cstdlib>

using namespace std;

int * init_array(int size) {
	int *a = new int[size];
	for(int i = 0; i < size; i++) {
		a[i] = rand() % size;
	}

	return a;
}

void print_array(int *a, int size) {
	for(int i = 0; i < size; i++) {
		cout << "a[" << i << "] is ";
		cout << a[i] << endl;
	}	
}

void insertion_sort(int *a, int size) {
    for(int i = 1; i < size; i++) {
        int cur = i;
        for(int j = i-1; (j >= 0) && (a[cur] < a[j]); j--) {
            int temp = a[cur];
            a[cur] = a[j];
            a[j] = temp;
            cur = j;
        }
    }
}

int main() {
	//Create an array of random numbers
    int *a = init_array(10);

	//print that array
	print_array(a, 10);

	//Run insertion sort
	insertion_sort(a, 10);
	
	//print line	
	cout << endl;
	
	//print sorted array
	print_array(a, 10);

	//delete a from heap
	delete[] a;

}
