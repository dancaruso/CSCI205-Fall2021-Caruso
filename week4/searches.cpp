#include <iostream>
#include <fstream>

using namespace std;

int binary_search(int *, int, int, int &);
int linear_search(int *, int, int, int &);
void fill_array(int *, int);

int main(){
	//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	ofstream f1("searches_linear.txt");
	ofstream f2("searches_binary.txt");

	int counts = 0;
	int index = 0;
	int N = 0;
	// execute 100 times with increasing problem size
	for (int i = 1; i < 100; ++i){
		// allocate and fill array
		N = i*100;
		int *array = new int[N];
		fill_array(array, N);

		// Call linear_search function
		counts = 0;
		index = linear_search(array, N, -1, counts);
		f1 << N << " " << counts << endl;
		
		// Call binary_search function
		counts = 0;
		index = binary_search(array, N, -1, counts);
		f2 << N << " " << counts << endl;

		delete[]  array;
	}
	return 0;
}

void fill_array(int *array, int size){
	for(int i = 0; i < size; ++i)
		array[i] = i + 1;
}

// For detailed explanation and analysis of these search functions, check out the instructions for this week's lab
int linear_search(int *array, int size, int key, int &counts){
	int index = -1;
	for(int i = 0; i < size; ++i){
		counts++;
		if(array[i] == key)
			return i;
	}
	return index;
}

int binary_search(int *array, int size, int key, int &counts){
	int index = -1;
	int first = 0;
	int last = size - 1;
	bool found = false;

	while (first <= last && !found){
		++counts;
		int midpoint = (first + last) / 2;
		if (array[midpoint] == key)
			return midpoint;
		if (key < array[midpoint])
			last = midpoint - 1;
		else
			first = midpoint + 1;
	}
	return index;
}
