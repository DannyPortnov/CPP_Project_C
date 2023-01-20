#ifndef _PQ_ITEM_H
#define _QUEUE_H_

#define   _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;

template <class T>
class PQ_Item {
private:
	int m_priority;
	T m_value;
public:
	PQ_Item(int priority, T value)
		:m_priority(priority), m_value(value){}

	int get_priority() { return m_priority; }
	T get_value() { return m_value; }
	void set_value(T value) { m_value = value; }
	void set_priority(int priority) { m_priority = priority; }
};


#endif // !_PQ_ITEM_H