#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#define MIN_SERVICE_TIME 50
#define MAX_SERVICE_TIME 69

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

template <class T>
class PriorityQueue {
	private:
		PQ_Item<T>** m_queue;	//queue array pointer
		PQ_Item<T>* m_head;
		PQ_Item<T>* m_tail;
		int m_size = 0; // current number of variables in queue

		void increment_pointer(PQ_Item<T>*& pointer) {

			if (pointer == m_queue[m_size - 1]) {
				pointer = m_queue[0];
			}
			else {
				pointer++;
			}
		}

	public:
		void push(const PQ_Item<T> new_item) {
			if (!is_queue_full()) {
				int i = 0;
				for (; i < m_size; i++)
				{
					PQ_Item<T>* queue_element = m_queue[i]; //compilter doesn't handle autocompletes appropriately!
					if (queue_element->get_priority() < item_to_push.get_priority()) {
						break;
					}

				}

				*m_tail = new_item;
				increment_pointer(m_tail);
			}
			else {
				return;
			}
			if (is_queue_empty()) { //checks if m_head is nullptr, not really empty because a client was pushed.
				if (m_tail == &m_queue[0]) {
					m_head = &m_queue[m_size - 1];
				}
				else {
					m_head = (m_tail - 1);
				}
			}
		}

		PriorityQueue(int size)
			:m_size(size), m_head(nullptr)
		{
			initialize_queue();
		}
		PriorityQueue& initialize_queue() {
			m_queue = new PQ_Item<T>*[m_size];
			m_tail = m_queue[0];
			return *this;
		}
		//PriorityQueue(const PriorityQueue<T>&) {
		//	m_queue = new PQ_Item<T>*[m_size];
		//	m_tail = m_queue[0];
		//	return *this;
		//}
		//~PriorityQueue() {// deconstructor
		//	delete[] m_queue;
		//}		
		PQ_Item<T>** get_queue() { return m_queue; }
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

#endif		// _PRIORITY_QUEUE_H_