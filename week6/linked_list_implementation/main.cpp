/*
    Assignment:   CSCI205 Week 6 Lab
    main_test.cpp - a tester main file to test linked list implementation functionality

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/8/2021
*/

#include <iostream>
#include "List.h"
using namespace std;

int main() {
    /*
    Linked List implementation checklist:
    (1) (DONE) No argument constructor
    (2) (DONE) Overloaded constructor: Accept a templated array as a parameter
    (3) (DONE) void insert(T item, int position);
    (4) (DONE) T get(int position);
    (5) (DONE) int find(T item);
    (6) (DONE) T removeItem(T item);
    (7) (DONE) T removePosition(int position);
    (8) (DONE) void print();
    (9) (DONE) int length();
    (10) (DONE) int count(item);
    (11) (DONE) void remove_duplicates();
    (12) (DONE)void reverse();
    (13) void append(&list)
    */
/*
    int intArray[] = {1, 2, 3, 4, 5};
    List<int> intList1(intArray);       // (2)
    intList1.print();                   // (8)
    cout << "Item at node 2: " << intList1.get(2) << endl;    // (4)
    cout << "Length of Linked List: " << intList1.length() << endl;  // (9)
    cout << "Node of the number 4: " << intList1.find(4) << endl;   // (5)
    cout << "Removing the number 2..." << intList1.removeItem(2) << endl; // (6)
    intList1.print();
    cout << "Removing the node at index 1..." << intList1.removePosition(1) << endl;  // (7)
    intList1.print();
    cout << "Inserting 13 at index 2..." << endl;
    intList1.insert(13, 2);  // (3)
    intList1.print();
*/
    List<char> charList1 = List<char>();  // (1)
    charList1.insertAtHead('E');
    charList1.insertAtHead('E');
    charList1.insertAtHead('E');
    charList1.insertAtHead('E');
    charList1.insertAtHead('W');
    charList1.print();
    cout << "Reversing order of charList1..." << endl;
    charList1.reverse();  // (12)
    charList1.print();
    cout << "Total number of E's in charList1: " << charList1.count('E') << endl;  // (10)
    cout << "Deleting duplicate E's..." << endl;
    charList1.remove_duplicates();  // (11)
    charList1.print();

    char charArray[] = {'K', 'O'};
    List<char> charList2 = List<char>(charArray);
    cout << "Appending charList2 to charList 1..." << endl;
    charList1.append(charList2);
    charList1.print();
}