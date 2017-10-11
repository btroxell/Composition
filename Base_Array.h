// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef _BASE_ARRAY_H_
#define _BASE_ARRAY_H_

#include <cstring>

template <typename T>
class Base_Array
{
public:

	typedef T type;

	Base_Array(void);

	Base_Array(size_t length);

	Base_Array(size_t length, T fill);

	Base_Array(const Base_Array<T> & arr);

	~Base_Array(void);

	typedef T type;

	virtual const Base_Array & operator = (const Base_Array & rhs);

	size_t size(void) const;

	size_t max_size(void) const;

	T & operator [] (size_t index);

	const T & operator [] (size_t index) const;

	T get(size_t index) const;

	void set(size_t index, T value);

	int find(T element) const;

	int find(T element, size_t start) const;

	bool operator == (const Base_Array & rhs) const;

	bool operator != (const Base_Array & rhs) const;

	void fill(T element);

protected:

	T * data_;

	size_t cur_size_;

	size_t max_size_;


};

//#include "Base_Array.inl"
#include "Base_Array.cpp"
#include "Base_Array.inl"

#endif
