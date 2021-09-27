/*
    Assignment:   CSCI205 Week 4 Lab
    exercises.cpp - an implementation file for analyzing efficiency in various algorithm exercises

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/23/2021
*/

#include <iostream>
#include <fstream>

using namespace std;

int e_1(int *, int);
int e_2(int *, int);
int e_3(int *, int);
int e_4(int *, int);
int e_5(int *, int);
void fill_array(int *, int);

int main(){
	ofstream e1("exercise_1.txt");
	ofstream e2("exercise_2.txt");
    ofstream e3("exercise_3.txt");
	ofstream e4("exercise_4.txt");
	ofstream e5("exercise_5.txt");

	int index = 0;
	// execute 100 times with increasing problem size
	for (int i = 1; i < 100; ++i){

		// allocate and fill array
		int *array = new int[i];
		fill_array(array, i);

		// Call e_1 function
		index = e_1(array, i);
		e1 << i << " " << index << endl;

		// Call e_2 function
		index = e_2(array, i);
		e2 << i << " " << index << endl;

		// Call e_3 function
		index = e_3(array, i);
		e3 << i << " " << index << endl;

		// Call e_4 function
		index = e_4(array, i);
		e4 << i << " " << index << endl;

		// Call e_5 function
		index = e_5(array, i);
		e5 << i << " " << index << endl;

		delete[]  array;
	}
	return 0;
}

void fill_array(int *array, int size){
	for(int i = 0; i < size; ++i)
		array[i] = i + 1;
}

/*
e_1 function:  Exercise 1
-Each time the function is called, it will execute the outer (first) for-loop the same number of times as the input size, 
	with the inner (second) loop executing the same number of times as the input size during each loop of the outer loop. 
	This, with a constant variable assignment and return statement, gives us a basic operation time of T(n) = n^2 + 2, 
	giving us a base case of O(n^2).
-Best possible case: if n = 1, then the function will only take 3 operations to complete, or O(1)
-Worst possible case: the function will operate with approximately O(n^2) steps
-As displayed in exercise_1_graph.png, this gives us a quadratic function for its big-O analysis.  You can also see this 
	reflected in the data (exercise_1.txt) where each y coordinate value is the same as the x coordinate value squared.
*/
int e_1(int *array, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			count = count + 1;
		}
	}
	return count;
}

/*
e_2 function:  Exercise 2
-Each time the function is called, it will execute the for-loop the same number of times as the input size. This, 
	with a constant variable assignment and return statement, gives us a basic operation time of T(n) = n + 2, 
	giving us a base case of O(n).
-Best possible case: if n = 1, then the function will only take 3 operations to complete, or O(1)
-Worst possible case: the function will operate with approximately O(n) steps
-As displayed in exercise_2_graph.png, this gives us a linear function for its big-O analysis.  You can also see this 
	reflected in the data (exercise_2.txt) where each y coordinate value is the same as the x coordinate value.
*/
int e_2(int *array, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count = count + 1;
	}
	return count;
}

/*
e_3 function:  Exercise 3
-Each time the function is called, the input size is divided by 2 repeatedly in a while loop until the number "equals" zero
	(using integer division to round down). This, with a constant variable assignment and return statement, gives us a basic 
	operation time of T(n/2) + 2, giving us a base case of O(log base2 n).
-Best possible case: the input size is 1, giving us O(1) operations
-Worst possible case: the function will operate with approximatelty O(log base2 n) steps
-This is displayed in exercise_3_graph.png, giving us a logarithmic function. In the data, you can see the y-values (steps taken) 
	increase then level off as the problem size increases.

*/
int e_3(int *array, int size) {
	int i = size;
	int count = 0;
	while (i > 0) {
		count = count + 1;
		i = i / 2;
	}
	return count;
}

/*
e_4 function:  Exercise 4
-Each time the function is called, it will execute the outer (first) for-loop the same number of times as the input size, 
	the next (second) loop executing the same number of times as the input size during each loop of the outer loop, with the 
	inner most loop executing as many times as the input size during each of the second loop's executions. This, with a 
	constant variable assignment and return statement, gives us a basic operation time of T(n) = n^3 + 2, 
	giving us a base case of O(n^3).
-Best possible case: if n = 1, then the function will only take 3 operations to complete, or O(1)
-Worst possible case: the function will operate with approximately O(n^3) steps
-As displayed in exercise_4_graph.png, this gives us a cubic function for its big-O analysis.  You can also see this 
	reflected in the data (exercise_4.txt) where each y coordinate value is the same as the x coordinate value cubed.
*/
int e_4(int *array, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				count = count + 1;
			}
		}
	}
	return count;
}

/*
e_5 function:  Exercise 5
-Each time the function is called, it will execute each of the three for-loops the same number of times as the input size. 
	This, with a constant variable assignment and return statement, gives us a basic operation time of T(n) = 3n + 2, 
	giving us a base case of O(n).
-Best possible case: if n = 1, then the function will only take 5 operations to complete, or O(1)
-Worst possible case: the function will operate with approximately O(n) steps
-As displayed in exercise_5_graph.png, this gives us a linear function for its big-O analysis.  You can also see this 
	reflected in the data (exercise_5.txt) where each y coordinate value is three times the x coordinate value.
*/
int e_5(int *array, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count = count + 1;
	}
	for (int j = 0; j < size; j++) {
		count = count + 1;
	}
	for (int k = 0; k < size; k++) {
		count = count + 1;
	}
	return count;
}
