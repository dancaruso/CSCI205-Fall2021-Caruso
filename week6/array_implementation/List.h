/*
    Assignment:   CSCI205 Week 6 Lab
    List.h - a header and implementation file/template for a dynamic array implementation of a List class

    Version       1.0 Beta
    Author        Dan Caruso
    Created       10/5/2021
*/

#ifndef H_LIST_ARRAY
#define H_LIST_ARRAY
using namespace std;

template <class T>
class List {
    private:
        T *memory_array;  // memory allocation for list elements
        unsigned int size;  // variable to hold the size
        unsigned int tally;          // variable to hold the number of items in the array
        void sizeDouble();
        bool isFirst(int position);

    public:
        // Constructors
        List();
        List(int arraySize);
        List(T *payload_array);
        ~List();

        // Methods
        void insert(T item, unsigned int position);
        T get(int position);
        int find(T item);
        T removeItem(T item);
        T removePosition(unsigned int position);
        void print();
        int length();
        int count(T item);
        void remove_duplicates();
        void reverse();
        void append(List<T> list);  
};
#endif

// No-argument constructor: initialize the array with a size of 10
template <class T>
List<T>::List() {
    size = 10;
    tally = 0;
    memory_array = new T[size];
}

// Overloaded constructor: accept the size as a parameter
template <class T>
List<T>::List(int arraySize) {
    size = arraySize;
    tally = 0;
    memory_array = new T[size];
}

// Overloaded constructor: Accept a templated array as a parameter which will hold a payload collection of items to initialize the list
template <class T>
List<T>::List(T *payload_array) {
    size = sizeof(*payload_array) + 1;
    tally = size;
    memory_array = new T[size];
    for (unsigned int i = 0; i < size; ++i) {
        memory_array[i] = payload_array[i];
    }
    sizeDouble();
}

// Destructor: Delete the current memory_array
template <class T>
List<T>::~List() {
    delete[] memory_array;
    size = 0;
}

// insert(item, position): Insert item at a position
// INCOMPLETE
template <class T>
void List<T>::insert(T item, unsigned int position) {
    size += 1;
    T *temp_array = new T[size];
    T next;
    for (unsigned int i = 0; i < size; ++i) {
        if (i < position) {
            temp_array[i] = memory_array[i];
        }
        else if (i == position) {
            next = memory_array[i];
            temp_array[i] = item;
        }
        else if (i == (size - 1)) {
            temp_array[i] = next;
        }
        else {
            temp_array[i] = next;
            next = memory_array[i];
        }
    }
    delete[] memory_array;
    memory_array = temp_array;
    tally += 1;
    sizeDouble();
}

// get(position): get item at position
template <class T>
T List<T>::get(int position) {
    return memory_array[position];
}

// find(item): find item and return its position
template <class T>
int List<T>::find(T item) {
    for (unsigned int i = 0; i < tally; ++i) {  // Iterate through memory_array
        if (memory_array[i] == item) {          // If the current item is what we're looking for, return that index
            return i;
        }
    }
    return -1;
}

// remove(item): remove and return item specified by the parameter
template <class T>
T List<T>::removeItem(T item) {
    unsigned int index = this->find(item);
    size -= 1;
    T *temp_array = new T[size];
    T next;
    T removed;          
    for (unsigned int i = 0; i < size; ++i) {  
        if (i < index) {          
            temp_array[i] = memory_array[i];
        }
        else if (i == index) {
            removed = item;
            next = memory_array[i + 1];
            temp_array[i] = next; 
        }
        else if (i == (size - 1)){
            temp_array[i] = next;
        }
        else {
            next = memory_array[i + 1];
            temp_array[i] = next;
        }
    }
    tally -= 1;                 // Set count to now be one less
    delete[] memory_array;      // Delete memory_array
    memory_array = temp_array;  // Set it equal to temp_array
    sizeDouble();
    return removed;
}

// remove(position): remove and return item at position
template <class T>
T List<T>::removePosition(unsigned int position) {
    size -= 1;
    T *temp_array = new T[size];
    T next;
    T removed;          
    for (unsigned int i = 0; i < size; ++i) {  
        if (i < position) {          
            temp_array[i] = memory_array[i];
        }
        else if (i == position) {
            removed = memory_array[position];
            next = memory_array[i + 1];
            temp_array[i] = next; 
        }
        else if (i == (size - 1)){
            temp_array[i] = next;
        }
        else {
            next = memory_array[i + 1];
            temp_array[i] = next;
        }
    }
    tally -= 1;                 // Set count to now be one less
    delete[] memory_array;      // Delete memory_array
    memory_array = temp_array;  // Set it equal to temp_array
    sizeDouble();
    return removed;
}

// print(): print list in some attractive format
template <class T>
void List<T>::print() {
    for (unsigned int i = 0; i < size; ++i) {
        if (i == 0) {
            cout << '{' << memory_array[i] << ", ";
        }
        else if (i == (size-1)) {
            std::cout << memory_array[i] << '}' << std::endl;
        }
        else {
            std::cout << memory_array[i] << ", ";
        }
    }
}

// length(): returns the number of elements in the list
template <class T>
int List<T>::length() {
    return tally;
}

// sizeDouble(): a provate helper method that resizes an array to double the current capacity if full
/* Algorithim analysis:
    -Best case scenario:  O(1) - algorithm would process once by not doubling the current array if the array isn't full
        (i.e. the count size of how many elements are present is less than the size of the array)
    -Worst case scenario:  O(n) - algorithm would process n number of times, n being the number of elements currently 
        in the array as elements are passed to a temporary array
*/
template <class T>
void List<T>::sizeDouble() {
    if (tally == size) {
        size = size * 2;                            // Change array size to double current capacity
        T *temp_array = new T[size];                // Create a temporary array of new size 
        for (unsigned int i = 0; i < tally; ++i) {  // Iterate through memory_array's contents, add to temp_array
            temp_array[i] = memory_array[i];
        }
        delete[] memory_array;                      // Delete memory_array
        memory_array = temp_array;                  // Set it equal to temp_array
    }
}

template <class T>
int List<T>::count(T item) {
    int total = 0;
    for (unsigned int i = 0; i < tally; ++i) {
        if (item == memory_array[i]) {
            total += 1;
        }
    }
    return total;
}

template <class T>
bool List<T>::isFirst(int position) {
    if (position == 0) {
        return true;
    }
    for (int i = 0; i < position; ++i) {
        if (memory_array[i] == memory_array[position]) {
            return false;
        }
    }
    return true;
}

template <class T>
void List<T>::remove_duplicates() {
    int positionCounter = 0;
	for (unsigned int i = 1; i < size; ++i) {
        positionCounter += 1;
		int counter = this->count(memory_array[positionCounter]);
		if ((counter > 1) && (this->isFirst(positionCounter) == false)) {
			this->removePosition(positionCounter);
            positionCounter -= 1;
		}
	}
}

template <class T>
void List<T>::reverse() {
	T *temp_array = new T[tally];
	for (unsigned int i = 0; i < tally; ++i) {
		temp_array[i] = memory_array[i];
	}
	for (unsigned int j = tally; j > 0; --j) {
		memory_array[tally - j] = temp_array[j - 1];
	}
}

template <class T>
void List<T>::append(List<T> list) {
    int indexStart = tally;
    for (unsigned int i = 0; i < list.tally; ++i) {
        memory_array[indexStart + i] = list.memory_array[i];
        tally += 1;
        sizeDouble();
    }
}
