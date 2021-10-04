/*
    Assignment:   CSCI205 Week 5 Lab
    stack.h - a header and implementation file/template for a stack

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/3/2021
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "deque.h"
using namespace std;

template <class T>
class Stack : protected Deque {
    public:
        // Constructor
        Stack(int setMax);

        // Destructor
        ~Stack();

        // Methods
        void push(const T item);
        T pop() const;
        T peek() const;
        bool is_empty();
};
#endif

template <class T>
Stack<T>::Stack(int setMax) {
    this.max = setMax;
    this.count = 0;
    this.tail = 0;
}

template <class T>
Stack<T>::~Stack() {
    delete[] this.data;
    this.count = 0;
    this.tail = 0;
}

template <class T>
void Stack<T>::push(const T item) {
    this.push_back();
}

template <class T>
T Stack<T>::pop() const {
    return this.remove_back();
}

template <class T>
T Stack<T>::peek() const {
    return this.data[tail];
}
