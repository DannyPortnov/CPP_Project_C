#ifndef _OUTOFRANGE_H_
#define _OUTOFRANGE_H_
#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class outOfRange : public exception {
private:
	string m_str;
public:
	outOfRange(string str = "out of range") : m_str(str) {};
	virtual const char * what() const {
		return m_str.c_str();
	}
};
#endif
