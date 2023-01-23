#include <corecrt_memory.h>
#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <string>
#include <iostream>
#include <sstream>
#include <outOfRange.h>

using namespace std;

template <class T>
class Array {

public:
	Array(int len = 10) : m_len(len), m_data(len ? (new T[len]) : NULL)
	{
		/*if (len)
			for (int i = 0; i < m_len; i++)
			{
				m_data[i] = 0;
			}*/
	}
	Array(const Array& otherArr) : m_len(otherArr.len()), m_data(m_len ? (new T[m_len]) : NULL) {

		for (int i = 0; i < m_len; i++)
		{
			m_data[i] = otherArr[i];
		}
	}
	~Array() { delete[] m_data; }
	int len() const { return m_len; }
	T& operator[](int i);
	T operator[](int i) const;
	void FormatExceptionMessage(const int i) const;
	Array& operator=(const Array& other_arr);
	friend ostream& operator<<(ostream& os, const Array& arr) {
		for (int i = 0; i < arr.len(); i++)
		{
			os << arr[i];
		}
		os << endl;
		return os;
	}
	friend bool operator<(const Array& firstArr, const Array& secondArray) {
		if (firstArr.len() > secondArray.len()) {
			return false;
		}
		else if (firstArr.len() < secondArray.len()) {
			return true;
		}
		for (int i = 0; i < firstArr.len(); i++)
		{
			if (firstArr[i] < secondArray[i]) {
				return true;
			}
			else if (firstArr[i] > secondArray[i]) {
				return false;
			}
		}
		return false;
	}

	void fill_Array(T value) {
		for (int i = 0; i < len(); i++)
			m_data[i] = value;
	}
private:
	int  m_len;
	T* m_data;
};

template <class T>
T& Array<T>::operator[](int i) {
	if (i > m_len - 1 || i < 0) {
		FormatExceptionMessage(i);
	}
	return m_data[i];
}

template <class T>
T Array<T>::operator[](int i) const { //only for const objects
	if (i > m_len - 1 || i < 0) {
		FormatExceptionMessage(i);
	}
	return m_data[i];
}

template <class T>
void Array<T>::FormatExceptionMessage(const int i) const
{
	stringstream ss;
	ss << "Invalid index " << to_string(i) << " in array of length " << to_string(m_len);
	outOfRange out_of_range_exception(ss.str());
	throw(out_of_range_exception);
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other_arr) {
	if (&other_arr == this)
		return *this;
	if (m_data)
		delete[] m_data;
	m_len = other_arr.m_len;
	if (m_len > 0)
		m_data = new T[m_len];
	for (int i = 0; i < m_len; i++) {
		m_data[i] = other_arr.m_data[i];
	}
	return *this;
}

#endif

//
//#include <corecrt_memory.h>
//#ifndef _ARRAY_H_
//#define _ARRAY_H_
//using namespace std;
//
//class Array {
//public:
//	Array(int len = 10) : m_len(len), m_data(len ? (new int[len]) : NULL)
//	{
//		if (len)
//			memset(m_data, 0, len * sizeof(int));
//	}
//	~Array() { delete[] m_data; }
//	int len() const { return m_len; }
//	int& operator[](int i);
//	int operator[](int i) const;
//	void FormatExceptionMessage(const int i) const;
//	Array& operator=(const Array& other_arr);
//
//private:
//	int  m_len;
//	int* m_data;
//};

