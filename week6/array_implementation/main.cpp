/*
    Assignment:   CSCI205 Week 6 Lab
    main_test.cpp - a tester main file to test array implementation functionality

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/7/2021
*/

#include <iostream>
#include "List.h"
using namespace std;

int main() {
/*
    Dynamic Array implementation checklist:
    (1) (DONE) No argument constructor
    (2) (DONE) Overloaded constructor: accept the size as a parameter
    (3) (DONE) Overloaded constructor: Accept a templated array as a parameter
    (4) Destructor
    (5) (DONE) void insert(item, position)
    (6) (DONE) T get(position)
    (7) (DONE) int find (item)
    (8) (DONE) T removeItem(item)
    (9) (DONE) T removePosition(position)
    (10) (DONE) void print()
    (11) (DONE) int length()
    (12) (DONE) int count(T item);
    (13) (DONE) void remove_duplicates();
    (14) (DONE) void reverse();
    (15) (Done) void append(List<T> list);  
*/
 /*    
    List<int> intList; // (1)
    intList.insert(13, 0); // (5)
    cout << intList.get(0) << endl; // (6)
    intList.print();
    List<char> charList(3); // (2)
    charList.insert('D', 0); // (5)
    charList.print();
    charList.insert('O', 1);
    charList.print();
    charList.insert('H', 2);
    charList.print(); // (10)
    cout << charList.length() << endl; // (11)
    cout << charList.get(2) << endl;
    cout << charList.find('O') << endl; // (7)
    cout << charList.find('L') << endl; // (7)
    cout << charList.removeItem('O') << endl;
    charList.print();
*/

    int intArray[] = {1, 2, 3, 4, 5};
    List<int> intList2(intArray); // (3)
    cout << "intlist2: ";
    intList2.print();
    cout << "Removing item at index 2: " << intList2.removePosition(2) << endl; // (9)
    intList2.print();
    cout << "Removing item at index 1: " << intList2.removeItem(1) << endl; // (8)
    intList2.print();
    cout << "Inserting a 1 at index 2..." << endl;
    intList2.insert(1, 2);
    intList2.print();
    cout << "Inserting a 1 at index 0..." << endl;
    intList2.insert(1, 0);
    intList2.print();
    cout << "Inserting a 1 at index 4..." << endl;
    intList2.insert(1, 4);
    intList2.print();
    cout << "Number of 1's in list: " << intList2.count(1) << endl;  // (12)
    cout << "Removing all duplicates from the list: " << endl;
    intList2.remove_duplicates();  // (13)
    intList2.print();
    cout << "REVERSE! REVERSE!" << endl;
    intList2.reverse();  // (14)
    intList2.print();
    cout << endl;

    int intArray2[] = {13, 14, 15, 16, 17};
    List<int> intList3(intArray2);
    cout << "intList3: ";
    intList3.print();
    cout << "Appending intList3 to intList2..." << endl;
    intList2.append(intList3);  // (15)
    intList2.print();
}
