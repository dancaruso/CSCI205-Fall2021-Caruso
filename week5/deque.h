/*
    Assignment:   CSCI205 Week 5 Lab
    deque.h - a header and implementation file/template for a deque

    Version       1.0 Beta
    Author        Dan Caruso
    Created       9/30/2021
*/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
using namespace std;

template <class T>
class Deque {
    protected:
        int max;
        int count;
        int head;
        int tail;
        T *data{};

    public:
        // Constructor
        Deque(int setMax);

        // Destructor
        ~Deque();

        // Methods
        void push_front(const T item);
        void push_back(const T item);
        T remove_front();
        T remove_back();
        int size() const;
        int capacity() const;
        bool is_full();
        bool is_empty();
};
#endif

template <class T>
Deque<T>::Deque(int setMax) {
    max = setMax;
    count = 0;
    head = 0;
    tail = 0;
    data = new T[setMax]{};
}

template <class T>
Deque<T>::~Deque() {
    delete[] data;
    count = 0;
    head = 0;
    tail = 0;
}

// push_front - pushes an item to the front (head) of the deque
// NOTE PER INSTRUCTIONS: don't need to deal with overflow, let the programmer have ability to check if full and act accordingly
template <class T>
void Deque<T>::push_front(const T item) {
    int temp_count = count;
    count += 1;                 // Add to the counter to track the deque size
    if ((temp_count == 0) && (count = 1)) {  // If the deque is seeing its first entry
        head = 0;
        tail = 0;
    }
    else {
        if (head == 0) {            // If the head of the deque is at index 0, set it to the last index
            head = (max - 1);
        }
        else {
            head -= 1;              // If not, just set the head of the deque to the next earliest index
        }
    }
    data[head] = item;          // Set the data item to this new head index
}

// push_back - pushes an item to the back (tail) of the deque
// NOTE PER INSTRUCTIONS: don't need to deal with overflow, let the programmer have ability to check if full and act accordingly
template <class T>
void Deque<T>::push_back(const T item) {
    int temp_count = count;
    count += 1;                 // Add to the counter to track the deque size
    if ((temp_count == 0) && (count = 1)) {  // If the deque is seeing its first entry
        head = 0;
        tail = 0;
    }
    else{
        if (tail == (max - 1)) {    // If the tail of the deque is at the last index, set it to the first index
            tail = 0;
        }
        else {
            tail += 1;              // If not, just set the tail of the deque to the next index
        }
    }
    data[tail] = item;          // Set the data item to this new tail index
}

// remove_front - removes the item at the front (head) of the deque
// NOTE PER INSTRUCTIONS: don't need to deal with underflow, let the programmer have ability to check if empty and act accordingly
template <class T>
T Deque<T>::remove_front() {
    T temp_data = data[head];
    data[head] = 0;          // Remove the data at the head by setting it to 0
    head += 1;                  // Push the position of the head back to the next value in line
    if (head == max) {          // If the new head index is greater than the max for the array, set it to the first index
        head = 0;
    }
    count -= 1;                 // Remove one from the size counter
    return temp_data;
}

// remove_back - removes the item at the back (tail) of the deque
// NOTE PER INSTRUCTIONS: don't need to deal with underflow, let the programmer have ability to check if empty and act accordingly
template <class T>
T Deque<T>::remove_back() {
    T temp_data = data[tail];
    data[tail] = 0;             // Remove the data at the tail by setting it to 0
    tail -= 1;                  // Pull the position of the tail up to the previous value in line
    if (tail < 0) {             // If the new tail index is less than the min for the array, set it to the last index
        tail = (max - 1);
    }
    count -= 1;                 // Remove one from the size counter
    return temp_data;
}

// size - returns the current size of the deque
template <class T>
int Deque<T>::size() const{
    return count;
}

// capacity - returns the max capacity of the deque
template <class T>
int Deque<T>::capacity() const{
    return max;
}

// is_full - checks to see if the deque is full
template <class T>
bool Deque<T>::is_full() {
    if (count == max) {
        return true;        // If the count equals the max capacity, return true
    }
    else {
        return false;       // If not return false
    }
}

// is_empty - checks to see if the deque is empty
template <class T>
bool Deque<T>::is_empty() {
    if (count == 0) {       // If the count is equal to zero, return true and set the head and tail indcies to 0
        head = 0;
        tail = 0;
        return true;
    }
    else {
        return false;       // If not return false
    }
}

