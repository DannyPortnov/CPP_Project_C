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

class PriorityQueue {
private:
	static mt19937 m_gen;    // Random-number engine used (Mersenne-Twister in this case)
	char* m_queue;	//queue array pointer
	char* m_head;
	char* m_tail;
	const int m_service_time;
	const int m_capacity;	// the queue's capacity 
	unsigned m_variables_count = 0; // number of variables in queue
	static unsigned queue_number; // number of class instances
	PriorityQueue& initialize_queue();
	void increment_pointer(char*& pointer); //ref to pointer
public:
	PriorityQueue(int capacity);
	PriorityQueue(const PriorityQueue&);
	~PriorityQueue();		// deconstructor
	void push(const char new_client);
	const bool pop();
	const bool is_queue_full() const;
	const bool is_queue_empty() const;
	const char front() const;
	const int size() const;
	const int get_service_time() const;
	static mt19937& get_random_num_gen();
};

const int random_func(const int min, const int max);

#endif		// _QUEUE_H_