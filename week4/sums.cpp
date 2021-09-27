/*
    Assignment:   CSCI205 Week 4 Lab
    sums.cpp - an implementation file for comparing efficiency in summing with iteration vs summation

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/23/2021
*/

#include <iostream>
#include <fstream>

using namespace std;

int iteration_sum(int *, int, int &);
int summation_sum(int *, int, int &);
void fill_array(int *, int);

int main(){
	ofstream s1("sums_iteration.txt");
	ofstream s2("sums_summation.txt");

	int counts = 0;
	int index = 0;
	int N = 0;

    // execute 100 times with increasing problem size
	for (int i = 1; i < 100; ++i){
		// allocate and fill array
		N = i*100;
		int *array = new int[N];
		fill_array(array, N);

		// Call iteration_sum function
		counts = 0;
		index = iteration_sum(array, N, counts);
		s1 << N << " " << counts << " " << index << endl;

		// Call summation_sum function
		counts = 0;
		index = summation_sum(array, N, counts);
		s2 << N << " " << counts << " " << index << endl;

		delete[]  array;
	}
	return 0;
}

void fill_array(int *array, int size){
	for(int i = 0; i < size; ++i)
		array[i] = i + 1;
}

/*
iteration_sum function: calculates the sum of a linear array of integers using iteration
-This problem has one assignment statement (sum = 0) and a return statement (which will take a constant time), plus 
	the number of times the program has to iterate and add each number up, having a basic computation of T(n) = c + n
-Best possible case: the function would only have a problem size of 1, taking O(1) operations to execute
-Worst possible case: the function would sum all values by iterating n number of times and adding each value, 
	taking approximately O(n) operations to work through all integers
-Average case: same as the worst possible case - the function would execute n times to iterate and add up each integer,
	taking approximately O(n) operations to work through all integers
-This is a linear function, so as you can see from sums_iteration_graph.png, the approximate number of steps executed is 
	the same as the problem size
*/
int iteration_sum(int *array, int size, int &counts) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		counts++;
		sum += array[i];
	}
	return sum;
}

/*
summation_sum function: calculates the sum of a linear array of integers using summation
-Each time the function calculates the sum, the summation equation will occur once no matter how big the problem size is, plus 
	a return statement, giving us an approximate running time of T(n) = 2
-Since this will solve the summation with these two steps, independant of problem size, this will always take O(1) operations 
	to execute in either best, worst, or average case scenarios
-This is a constant function, which is reflected in sums_summation_graph.png where no matter how big the problem size is, 
	the number of operations always stays the same (flat line along x-axis)
*/
int summation_sum(int *array, int size, int &counts) {
	int sum = ((size * (size + 1)) / 2);
	counts++;
	return sum;
}

/*
Conclusion: the summation function is a lot more efficient, and would be especially effective as problems sizes increase
**NOTE** For my formatted text output files for each of these sum functions, I also included the total final sum with each data 
	point to verify that both methods were calculating the same results
*/
