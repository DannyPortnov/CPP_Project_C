#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

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
    int m_current_size;
    int m_capacity;
    PQ_Item<T>** m_queue;
    int allocations_counter = 0; //counts number of dynamic 
    void prioritize_elements(int index);
    void resize();
public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& other);
    ~PriorityQueue();
    //PriorityQueue<T>& get();
    void insert(T value, int priority);
    T remove();
    int get_size() const;
    PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
};

template<class T>
PriorityQueue<T>::PriorityQueue() : m_current_size(0), m_capacity(1), m_queue(new PQ_Item<T>* [m_capacity]) {
}
template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other) : m_current_size(other.m_current_size), 
    m_capacity(other.m_capacity), m_queue(new PQ_Item<T>* [other.m_capacity]) {
    for (int i = 0; i < m_current_size; i++) {
        m_queue[i] = other.m_queue[i];
    }
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
    for (int i = 0; i < allocations_counter; i++)
    {
        delete m_queue[i];
    }
    delete[] m_queue;
}

//inserts an element to the queue based on its priority, to the currect possion
//resized the queue if needed.
template<class T>
void PriorityQueue<T>::insert(T value, int priority) {
    if (m_current_size == m_capacity) {
        resize();
    }
    m_queue[m_current_size] = new PQ_Item<T>(priority, value);
    allocations_counter++;
    m_current_size++;
    prioritize_elements(m_current_size - 1);
}

//removes the top element. if the queue is empty throws exception.
template<class T>
T PriorityQueue<T>::remove() {
    if (m_current_size == 0) { //is empty
        throw "Cannot remove an element from an empty queue";
    }
    T highestPriorityValue = m_queue[0]->get_value();
    delete m_queue[0];
    m_current_size--;
    allocations_counter--;
    if (m_current_size > 0) {
        for (int i = 0; i < m_current_size; i++)
        {
            m_queue[i] = m_queue[i + 1];
        }
    }
    return highestPriorityValue;
}

//returns current number of elements in the queue
template<class T>
int PriorityQueue<T>::get_size() const {
    return m_current_size;
}

template<class T>
void PriorityQueue<T>::resize() {
    //was_resized = true;
    m_capacity+=1;
    PQ_Item<T>** newArray = new PQ_Item<T>*[m_capacity];
    for (int i = 0; i < m_current_size; i++) {
        newArray[i] = m_queue[i];
    }
    delete[] m_queue;
    m_queue = newArray;
}

//swaps between a and b
template <class T>
void my_swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

//re-arrenges the elements based on their priority in the queue
template<class T>
void PriorityQueue<T>::prioritize_elements(int index) {
    int i = index - 1;
    if (index > 0 && m_queue[index]->get_priority() > m_queue[i]->get_priority()) {
        my_swap(m_queue[index], m_queue[i]);
        prioritize_elements(i);
    }
}

template<class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
    if (this != &other) {
        m_current_size = other.m_current_size;
        m_capacity = other.m_capacity;
        delete[] m_queue;
        m_queue = new PQ_Item<T>**[m_capacity];
        for (int i = 0; i < m_current_size; i++) {
            m_queue[i] = other.m_queue[i];
        }
    }
    return *this;
}

#endif		// _PRIORITY_QUEUE_H_