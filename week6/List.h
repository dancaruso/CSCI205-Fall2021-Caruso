/*
    Assignment:   CSCI205 Week 6 Lab
    List.h - a header and implementation file/template for a linked list implementation of a List class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/8/2021
*/

#ifndef H_List_ARRAY
#define H_LIST_ARRAY
using namespace std;

#include "LinkedList.h"

template <class T>
class List : protected LinkedList<T> {
    private:
        LinkedList<T> *memory_list;    // memory allocation for list elements
        unsigned int size;      // variable to hold the size
        int counter = 0;

    public:
        List();
        List(T *payload_array);
        ~List();

        // Methods
        void insertAtHead(T item);
        void insert(T item, int position);
        T get(int position);
        int find(T item);
        T removeItem(T item);
        T removePosition(int position);
        void print();
        int length();
        int count(T item);
        void remove_duplicates();
        void reverse();
        void append(List<T> list);
};
#endif

template <class T>
List<T>::List() {
    memory_list = new LinkedList<T>();
    size = 0;
}

template <class T>
List<T>::List(T *payload_array) {
    size = sizeof(*payload_array) + 1;
    memory_list = new LinkedList<T>();
    for (unsigned int i = 0; i < size; ++i) {
        memory_list->insertAtHead(payload_array[i]);
    }
}

template <class T>
List<T>::~List() {
    delete memory_list;
    size = 0;
}

template <class T>
void List<T>::insertAtHead(T item) {
    memory_list->insertAtHead(item);
}

template <class T>
void List<T>::insert(T item, int position) {
    memory_list->insert(item, position);
}

template <class T>
T List<T>::get(int position) {
    return memory_list->getItem(position);
}

template <class T>
int List<T>::find(T item) {
    return memory_list->getPosition(item);
}

template <class T>
T List<T>::removeItem(T item) {
    return memory_list->removeItem(item);
}

template <class T>
T List<T>::removePosition(int position) {
    return memory_list->removePosition(position);
}

template <class T>
void List<T>::print() {
    memory_list->printList();
}

template <class T>
int List<T>::length() {
    return memory_list->size();
}

template <class T>
int List<T>::count(T item) {
    return memory_list->tally(item);
}

template <class T>
void List<T>::remove_duplicates() {
    memory_list->remove_duplicates();
}

template <class T>
void List<T>::reverse() {
    memory_list->reverse();
}

template <class T>
void List<T>::append(List<T> list) {
    while (counter <= list.length()) {
        memory_list->insertAtTail(list.removePosition(0));
        counter += 1;
    }
}
