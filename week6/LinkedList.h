/*
    Assignment:   CSCI205 Week 6 Lab
    LinkedList.h - a header and implementation file/template for a linked list

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/8/2021
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
using namespace std;

#include <iostream>


// The structure describing the node
// This could also be a class
template <class T>
struct Node{
	T item;				// address of data object. The node's "payload"
	Node<T>* next;		// pointer to the "next" node
};

template <class T>
class LinkedList {
	protected:
		Node<T>* head;	// pointer to beginning of list
		unsigned int count;		// number of elements

	public:
		LinkedList();
		~LinkedList(); 		// what needs to happen here?
		void insertAtHead(const T item);
		void insertAtTail(const T item);
		void insert(const T item, unsigned int position);
		int size() const;
		bool isEmpty();
		void printList();
		T removeHead();
		T removeItem(T item);
		T removePosition(unsigned int position);
		T getItem(unsigned int position);
		int getPosition(T item);
		int tally(T item);
		void remove_duplicates();
    	void reverse();
    	//void append(LinkedList<T> list);
};
#endif

template <class T>
LinkedList<T>::LinkedList() {
	//cout << "List constructor called" << endl; // just for visual clues
	head = NULL;		// head of a new list should be null
	count = 0;			// size of new list should zero
}

template <class T>
LinkedList<T>::~LinkedList(){
	//cout << "List destructor called" << endl; 	// just for visual clues
	Node<T> *current = head;			// start deleting at head
	while (current != NULL){			// iterate until we find a next NULL reference
		//cout << "Node deleted" << endl;	// just for visual clues
		Node<T> *next = current->next;	// advance "current" pointer to "next"
		delete current;					// deallocate the memory pointed to by "current"
		current = next;					// set current to "next"
	}
	head = NULL;						// set head to NULL
}

template <class T>
int LinkedList<T>::size() const{
	return count;
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return count == 0;
}

template <class T>
void LinkedList<T>::insertAtHead(const T item){
	//cout << "Data Inserted: " << data << endl; // just for visual clues
	Node<T> *temp = new Node<T>();	// instantiate new node to contain item
									// dynamic memory allocation in a method call
									// this method can be called N times during program execution

	temp->item = item;				// assign the new node its "payload". Templated for flexibility

	// check to see if this is the first item added
	// need to configure the "head" reference if so
	if(this->isEmpty()) head = temp;
	else{
									// not first item added
		temp->next = head;			// push old "head" down the list
		head = temp;				// new item then becomes the head
	}
	++count;						// increase the size
}

template <class T>
void LinkedList<T>::insertAtTail(const T item) {
	Node<T> *temp = new Node<T>();
	temp->item = item;
	Node<T> *current = head;
	Node<T> *previous = head;
	current = current->next;
	if (this->isEmpty()) {
		head = temp;
	}
	else {
		for (unsigned int i = 0; i < count; ++i) {
			if (i == (count - 1)) {
				previous->next = temp;
			}
			else {
				previous = previous->next;
				current = current->next;
			}
		}
	}
	count += 1;
}

template <class T>
void LinkedList<T>::insert(const T item, unsigned int position){
	Node<T> *temp = new Node<T>();
	temp->item = item;
	Node<T> *current = head;
	Node<T> *previous = head;

	for (unsigned int i = 0; i < count; ++i) {
		if (i == 0) {
			if (i == position) {
				head = temp;
			}
			current = current->next;
		}
		else{ 
			if (i == position) {
				previous->next = temp;
				temp->next = current;
				current = current->next;
				break;
			}
			else {
				previous = previous->next;
				current = current->next;
			}
		}
	}
	++count;
}

template <class T>
T LinkedList<T>::removeHead(){
	T temp = head->item;			// extract payload
	Node<T>* temp_head = head;		// stash current head for deallocation		
	head = head->next;				// make "next" node the new "head"
	delete temp_head;				// deallocate old "head"
	--count;						// decrease size
	return temp;					// return payload
}

template <class T>
T LinkedList<T>::removeItem(T item) {
	Node<T> *current = head;
	Node<T> *previous = head;
	T removedItem;
	for (unsigned int i = 0; i < count; ++i) {
		if (i == 0) {
			if (item == current->item) {
			removedItem = this->removeHead();
			break;
			}
			current = current->next;
		}
		else {
			if (item == current->item) {
				removedItem = current->item;
				Node<T> *tempCurrent = current;
				previous->next = current->next;
				current = current->next;
				delete tempCurrent;
				count -= 1;
				break;
			}
			else {
				previous = previous->next;
				current = current->next;
			}
		}
	}
	return removedItem;
}

template <class T>
T LinkedList<T>::removePosition(unsigned int position) {
	Node<T> *current = head;
	Node<T> *previous = head;
	T removedItem;
	for (unsigned int i = 0; i < count; ++i) {
		if (i == 0) {
			if (i == position) {
			removedItem = this->removeHead();
			break;
			}
			current = current->next;
		}
		else {
			if (i == position) {
				removedItem = current->item;
				Node<T> *tempCurrent = current;
				previous->next = current->next;
				current = current->next;
				delete tempCurrent;
				count -= 1;
				break;
			}
			else {
				previous = previous->next;
				current = current->next;
			}
		}
	}
	return removedItem;
}

// demonstrates linked list traversal
template <class T>
void LinkedList<T>::printList(){			// Be sure to overload << in any class you'll use
	Node<T> *current = head;		// start at the head
	int count = 0;					// enumerate just for kicks
	while(current != NULL){			// loop until current is null
		cout << "<Node " << count++ << ": " << current->item << "> ==> ";
		current = current->next;	// step the reference down the list
	}
	cout << "NULL" << endl;
}

template <class T>
T LinkedList<T>::getItem(unsigned int position) {
	Node<T> *current = head;
    unsigned int count = 0;
	T tempItem;
	while (current != NULL) {
		if (count == position) {
			tempItem = current->item;
		}
		current = current->next;
		count += 1;
	}
	return tempItem;
}

template <class T>
int LinkedList<T>::getPosition(T item) {
	Node<T> *current = head;
	unsigned int count = 0;
	int position = 0;
	while (current != NULL) {
		if (item == current->item) {
			position = count;
		}
		current = current->next;
		count += 1;
	}
	return position;
}

template <class T>
int LinkedList<T>::tally(T item) {
	Node<T> *current = head;
	int total = 0;
	for (unsigned int i = 0; i < count; ++i) {
		if (item == current->item) {
			total += 1;
		}
		current = current->next;
	}
	return total;
}

template <class T>
void LinkedList<T>::remove_duplicates() {
	Node<T> *current = head;
	T *memory_array = new T[count];
	unsigned int array_length = 0;
	for (unsigned int i = 0; i < count; ++i) {
		memory_array[i] = current->item;
		current = current->next;
		array_length += 1;
	}
	current = head;
	for (unsigned int j = 0; j < array_length; ++j) {
		int tally = this->tally(memory_array[j]);
		if (tally > 1) {
			this->removeItem(memory_array[j]);
		}
	}
}

template <class T>
void LinkedList<T>::reverse() {
	Node<T> *current = head;
	T *memory_array = new T[count];
	for (unsigned int i = 0; i < count; ++i) {
		memory_array[i] = current->item;
		current = current->next;
	}
	current = head;
	for (unsigned int j = count; j > 0; --j) {
		current->item = memory_array[j - 1];
		current = current->next;
	}
}

