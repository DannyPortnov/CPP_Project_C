#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#define initial_capacity 3

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
    int m_current_size;
    int m_max_capacity;
    PQ_Item<T>** m_queue;
    int allocations_counter = 0;
    void heapifyUp(int index);
    void heapifyDown(int index);
    void resize();
    void quick_sort(PQ_Item<T>* a[], int n);

    int partition(PQ_Item<T>* a[], int n);

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
PriorityQueue<T>::PriorityQueue() : m_current_size(0), m_max_capacity(initial_capacity), m_queue(new PQ_Item<T>* [m_max_capacity]) {
    //m_current_size = 0;
    //m_max_capacity = 10;
    //m_queue = new PQ_Item<T>*[m_max_capacity];
    //for (int i = 0; i < m_max_capacity; i++) {
    //    m_queue[i] = new Queue(m_q_capacity);
    //}
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
    //int amount_to_delete = m_current_size;
    //if (was_resized) {
    //    amount_to_delete+=2;
    //}
    for (int i = 0; i < allocations_counter; i++)
    {
        delete m_queue[i];
    }
    delete[] m_queue;
}

template<class T>
void PriorityQueue<T>::insert(T value, int priority) {
    if (m_current_size == m_max_capacity) {
        resize();
    }
    m_queue[m_current_size] = new PQ_Item<T>(priority, value);
    allocations_counter++;
    //m_queue[m_current_size]->set_value(value);
    //m_queue[m_current_size]->set_priority(priority);
    m_current_size++;
    heapifyUp(m_current_size - 1);
}

template<class T>
T PriorityQueue<T>::remove() {
    T highestPriorityValue = m_queue[0]->get_value();
    delete m_queue[0];
    m_current_size--;
    allocations_counter--;
    //m_queue[0] = m_queue[m_current_size - 1];
    if (m_current_size > 0) {
        for (int i = 0; i < m_current_size; i++)
        {
            m_queue[i] = m_queue[i + 1];
        }
    }
    //delete m_queue[0];
    //m_current_size--;
    //heapifyDown(0);
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
    //was_resized = true;
    m_max_capacity+=1;
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
    int parentIndex = index - 1;
    if (index > 0 && m_queue[index]->get_priority() > m_queue[parentIndex]->get_priority()) {
        my_swap(m_queue[index], m_queue[parentIndex]);
        heapifyUp(parentIndex);
    }
}

template<class T>
void PriorityQueue<T>::quick_sort(PQ_Item<T>* a[], int n) {
    if (n <= 1)
        return;
    int t = partition(a, n); // rearrange array
    quick_sort(a, t);
    quick_sort(a + t + 1, n - t - 1);
}
template<class T>
int PriorityQueue<T>::partition(PQ_Item<T>* a[], int n) {
    int pivot = a[0]->get_priority();
    int b = 1, t = n - 1;
    while (b <= t) {
        while (b <= t && a[b]->get_priority() < pivot)
            b++;
        while (t >= b && a[b]->get_priority() >= pivot)
            t--;
        if (b < t) {
            swap(&a[b++], &a[t--]);
        }
    }
    swap(&a[0], &a[t]);
    return t;
}

template<class T>
void PriorityQueue<T>::heapifyDown(int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallestIndex = index;
    if (leftChildIndex < m_current_size && m_queue[leftChildIndex]->get_priority() > m_queue[smallestIndex]->get_priority()) {
        smallestIndex = leftChildIndex;
    }
    if (rightChildIndex < m_current_size && m_queue[rightChildIndex]->get_priority() > m_queue[smallestIndex]->get_priority()) {
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