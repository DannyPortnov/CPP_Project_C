#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#define initial_capacity 10

#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <stdbool.h>
#include <string>
#include "PQ_Item.h"
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

template<class T>
class PriorityQueue {
private:
    //struct PQ_Item {
    //    T m_value;
    //    int m_priority;
    //};
    PQ_Item<T>** m_queue;
    int m_current_size;
    int m_max_capacity;

    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& other);
    ~PriorityQueue();
    void insert(T value, int priority);
    T remove();
    int getSize();
    void clear();
    PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
};

template<class T>
PriorityQueue<T>::PriorityQueue() /*: m_current_size(0), m_max_capacity(initial_capacity), m_queue(new PQ_Item[m_max_capacity])*/ {
    m_current_size = 0;
    m_max_capacity = 10;
    m_queue = new PQ_Item<T>*[m_max_capacity];
}
template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other) {
    m_current_size = other.m_current_size;
    m_max_capacity = other.m_max_capacity;
    m_queue = new PQ_Item<T>*[m_max_capacity];
    for (int i = 0; i < m_current_size; i++) {
        m_queue[i] = other.m_queue[i];
    }
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] m_queue;
}

template<class T>
void PriorityQueue<T>::insert(T value, int priority) {
    if (m_current_size == m_max_capacity) {
        resize();
    }
    m_queue[m_current_size]->set_value(value);
    m_queue[m_current_size]->set_priority(priority);
    m_current_size++;
    heapifyUp(m_current_size - 1);
}

template<class T>
T PriorityQueue<T>::remove() {
    T highestPriorityValue = m_queue[0]->get_value();
    m_queue[0] = m_queue[m_current_size - 1];
    m_current_size--;
    heapifyDown(0);
    return highestPriorityValue;
}

template<class T>
int PriorityQueue<T>::getSize() {
    return m_current_size;
}

template<class T>
void PriorityQueue<T>::clear() {
    m_current_size = 0;
}

template<class T>
void PriorityQueue<T>::resize() {
    m_max_capacity *= 2;
    PQ_Item<T>** newArray = new PQ_Item<T>*[m_max_capacity];
    for (int i = 0; i < m_current_size; i++) {
        newArray[i] = m_queue[i];
    }
    delete[] m_queue;
    m_queue = newArray;
}

template <class T>
void my_swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<class T>
void PriorityQueue<T>::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    if (index > 0 && m_queue[index]->get_priority() < m_queue[parentIndex]->get_priority()) {
        my_swap(m_queue[index], m_queue[parentIndex]);
        heapifyUp(parentIndex);
    }
}

template<class T>
void PriorityQueue<T>::heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallestIndex = index;
    if (leftChildIndex < m_current_size && m_queue[leftChildIndex]->get_priority() < m_queue[smallestIndex]->get_priority()) {
        smallestIndex = leftChildIndex;
    }
    if (rightChildIndex < m_current_size && m_queue[rightChildIndex]->get_priority() < m_queue[smallestIndex]->get_priority()) {
        smallestIndex = rightChildIndex;
    }
    if (smallestIndex != index) {
        my_swap(m_queue[index], m_queue[smallestIndex]);
        heapifyDown(smallestIndex);
    }
}

template<class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
    //if (this != &other) {
    //    m_current_size = other.m_current_size;
    //    m_max_capacity = other.m_max_capacity;
    //    delete[] m_queue;
    //    m_queue = new PQ_Item<T>**[m_max_capacity];
    //    for (int i = 0; i < size; i++) {
    //        m_queue[i] = other.m_queue[i];
    //    }
    //}
    return *this;
}

#endif		// _PRIORITY_QUEUE_H_