#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MIN_SERVICE_TIME 50
#define MAX_SERVICE_TIME 69

#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <stdbool.h>
#include <string>
#include <random>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

template <class T>
class PriorityQueue {
private:
	T* m_queue;	//queue array pointer
	T* m_head;
	T* m_tail;
	const unsigned m_priority;
	unsigned m_size = 0; // number of variables in queue
	void increment_pointer(T*& pointer) {
		if (pointer == &m_queue[m_capacity - 1]) {
			pointer = &m_queue[0];
		}
		else {
			pointer++;
		}
	}
public:
	PriorityQueue::PriorityQueue(int capacity)
		:m_capacity(capacity), m_head(nullptr)
	{
		initialize_queue();
	}
	PriorityQueue(const PriorityQueue&) {
		m_queue = new char[m_capacity];
		m_tail = &m_queue[0];
		return *this;
	}
	~PriorityQueue() {// deconstructor
		delete[] m_queue;
	}		
	void push(const T new_client) {
		if (!is_queue_full()) {
			*m_tail = new_client;
			increment_pointer(m_tail);
			m_variables_count++;
		}
		else {
			return;
		}
		if (is_queue_empty()) { //checks if m_head is nullptr, not really empty because a client was pushed.
			if (m_tail == &m_queue[0]) {
				m_head = &m_queue[m_capacity - 1];
			}
			else {
				m_head = (m_tail - 1);
			}
		}
	}
	const bool pop() {
		if (is_queue_empty()) {
			return false;
		}
		*m_head = NULL; //remove client
		increment_pointer(m_head);
		if (m_tail == m_head) {
			m_head = nullptr;
		}
		m_size--;

		return true;
	}
	const bool is_queue_full()  const {
		return m_tail == m_head;
	}

	const bool is_queue_empty()  const {
		return m_head == nullptr;
	}
	const char front() const {
		if (!is_queue_empty())
			return *m_head;
		cout << "The Queue Is Empty!" << endl;
	}

	const int size() const {
		return m_size;
	}
};


#endif		// _QUEUE_H_