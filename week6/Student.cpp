/*
    Assignment:   CSCI205 Week 6 Lab
    Student.cpp - an implementation file/template for a Student class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/10/2021
*/

#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(int id, string name, string dorm){
	this->id 	= id;
	this->name 	= name;
	this->dorm	= dorm;
}

int Student::getID() const{
	return this->id;
}

string Student::getName() const{
	return this->name;
}

string Student::getDorm() const{
	return this->dorm;
}

void Student::print() {
	cout << id << ", " << name << ", " << dorm << endl;
}
