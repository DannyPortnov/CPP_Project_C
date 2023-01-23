//#include "Array.h"
//#include "outOfRange.h"
//#include <string>
//#include <sstream>
//
//int& Array::operator[](int i) {
//	if (i > m_len - 1 || i < 0) {
//		FormatExceptionMessage(i);
//	}
//	return m_data[i];
//}
//
//int Array::operator[](int i) const { //only for const objects
//	if (i > m_len - 1 || i < 0) {
//		FormatExceptionMessage(i);
//	}
//	return m_data[i];
//}
//
//void Array::FormatExceptionMessage(const int i) const
//{
//	stringstream ss;
//	ss << "Exception: Invalid index: " << to_string(i) << " in int array of length " << to_string(m_len) << endl;
//	outOfRange oof(ss.str());
//	throw(oof);
//}
//
//
//Array& Array::operator=(const Array& other_arr) {
//	if (&other_arr == this)
//		return *this;
//	if (m_data)
//		delete[] m_data;
//	m_len = other_arr.m_len;
//	if (m_len > 0)
//		m_data = new int[m_len];
//	for (int i = 0; i < m_len; i++) {
//		m_data[i] = other_arr.m_data[i];
//	}
//	return *this;
//}
//
//
