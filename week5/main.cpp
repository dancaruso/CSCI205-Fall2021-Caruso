/*
    Assignment:   CSCI205 Week 5 Lab
    main.cpp - a main function for displaying deque, stack, and queue functionality

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/30/2021
*/

#include <iostream>
#include "deque.h"
//#include "stack.h"
using namespace std;

int main() {
    // Test deque with type int
    Deque<int> intDeque(4);
    cout << "Is the deque empty?: " << intDeque.is_empty() << endl;
    cout << "Max capacity for deque: " << intDeque.capacity() << endl;
    cout << "Adding 13 to the back..." << endl;
    intDeque.push_back(13);
    cout << "Adding 14 to the back..." << endl;
    intDeque.push_back(14);
    cout << "Is the deque empty?: " << intDeque.is_empty() << endl;
    cout << "Removing last value (back): " << intDeque.remove_back() << endl;
    cout << "Adding 15 to the front..." << endl;
    intDeque.push_front(15);
    cout << "Adding 16 to the back..." << endl;
    intDeque.push_back(16);
    cout << "Adding 17 to the front..." << endl;
    intDeque.push_front(17);
    cout << "Is the deque full?: " << intDeque.is_full() << endl;
    cout << "Removing first value (front): " << intDeque.remove_front() << endl;
    cout << "Removing last value (back): " << intDeque.remove_back() << endl;    
    cout << "Removing first value (front): " << intDeque.remove_front() << endl;
    cout << endl;

    // Test deque/template function with a different data type (char)
    Deque<char> charDeque(4);
    cout << "Is the deque empty?: " << charDeque.is_empty() << endl;
    cout << "Max capacity for deque: " << charDeque.capacity() << endl;
    cout << "Adding 'a' to the back..." << endl;
    charDeque.push_back('a');
    cout << "Adding 'b' to the back..." << endl;
    charDeque.push_back('b');
    cout << "Is the deque empty?: " << charDeque.is_empty() << endl;
    cout << "Removing last value (back): " << charDeque.remove_back() << endl;
    cout << "Adding 'c' to the front..." << endl;
    charDeque.push_front('c');
    cout << "Adding 'd' to the back..." << endl;
    charDeque.push_back('d');
    cout << "Adding 'e' to the front..." << endl;
    charDeque.push_front('e');
    cout << "Is the deque full?: " << charDeque.is_full() << endl;
    cout << "Removing first value (front): " << charDeque.remove_front() << endl;
    cout << "Removing last value (back): " << charDeque.remove_back() << endl;    
    cout << "Removing first value (front): " << charDeque.remove_front() << endl;
    cout << endl;

    // Test stack with type int
    // Investigate further as to why stack.h isn't properly inheriting from deque.h 
    //Stack<int> intStack(3);
    //cout << "Is the stack empty?: " << intStack.is_empty() << endl;
    
}