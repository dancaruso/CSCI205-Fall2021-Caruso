/*
    Assignment:   CSCI205 Week 6 Lab
    main.cpp - a main implementation file/template for a the Week 6 lab

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/10/2021
*/

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>
#include <random>
#include <ctime>
#include "Student.h"
#include "List.h"

using namespace std;

void load_dorms(unordered_map<string, List<string>>&);
void print_dorms(unordered_map<string, List<string>>&);

int main(){
	unordered_map<string, List<Student>> dorm_rosters;
	load_dorms(dorm_rosters);

	// Establish dorms
	ifstream dorm_file("dormFile.txt");
	vector<string> dormList;
	string dorm;
	while (getline(dorm_file, dorm)) {
		dormList.push_back(dorm);
	}
	cout << "Number of dorms: " << dormList.size() << endl;
	cout << "Available dorms: " << endl;
	for (unsigned int j = 0; j < dormList.size(); ++j) {
		cout << dormList[j] << endl;
	}

	// Establish student roster
	vector<Student> studentRoster;
	vector<string> studentIn;
	ifstream student_file("studentFile.txt");
	unsigned int studentCount = 0;
	string line;
	while (getline(student_file, line)) {
		studentCount += 1;
		stringstream inputStream(line);
		while (inputStream.good()) {
			string item;
			getline(inputStream, item, ' ');
			studentIn.push_back(item);
		}
	}

	// Establish dorm sorting (random)
	vector<int> dormOrder(studentCount, 0);
	vector<int> dormTally(dormList.size(), 0);
	for (unsigned int n = 0; n < studentCount; ++n) {
		dormOrder[n] = (n % dormList.size());
	}
	int tempIndex;
	srand(time(0));
	for (unsigned int n = 0; n < dormOrder.size(); ++n) {
		int tradePlace1 = (rand() % (dormOrder.size()));
		int tradePlace2 = (rand() % (dormOrder.size()));
		tempIndex = dormOrder[tradePlace1];
    	dormOrder[tradePlace1] = dormOrder[tradePlace2]; 
        dormOrder[tradePlace2] = tempIndex;  
	}

	// Establish list of student objects
	for(unsigned int i = 0; i < (studentCount * 2); ++i) {
		vector<int> dormTally(dormList.size(), 0);
		if ((i == 0) || (i % 2 == 0)) {
			int studentID = stoi(studentIn[i]);
			string studentName = studentIn[i + 1];
			string studentDorm = dormList[dormOrder[i/2]];
			Student tempStudent(studentID, studentName, studentDorm);
			studentRoster.push_back(tempStudent);
		}
	}
	for (unsigned int k = 0; k < studentRoster.size(); ++k) {
		studentRoster[k].print();
	}

	for (unsigned int i = 0; i < dormList.size(); ++i) {
		dorm_rosters[dormList[i]] = List<Student>();
		string dormName = dormList[i];
		ofstream outputFile(dormName + ".txt");
		for (unsigned int j = 0; j < studentRoster.size(); ++j) {
			if (studentRoster[j].getDorm() == dormName) {
				dorm_rosters[dormName].insert(studentRoster[j], 0);
				outputFile << studentRoster[j].getID() << " " << studentRoster[j].getName() << " " << studentRoster[j].getDorm() << endl;
			}
		}
	}



	return 0;
}

// this will need to change to also handle the list 
void load_dorms(unordered_map<string, List<Student>>& dorms){
	ifstream input_file("dormFile.txt");
	string dorm;
	while(getline (input_file, dorm)){
		dorms[dorm] = List<Student>();
	}
}

void print_dorms(unordered_map<string, List<string>>& dorms){
	for(auto dorm : dorms) // a "Pair" object is retured from a map
		// extract "first" and "second" from the Pair object
		cout << dorm.first << endl;
}
