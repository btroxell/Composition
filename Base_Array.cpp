// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Base_Array.h"
#include <stdexcept>
#include <iostream>

template <typename T>
Base_Array <T>::Base_Array(void)
	: data_(new T[0]), cur_size_(0), maz_size_(0)
{

}

template <typename T>
Base_Array <T>::Base_Array(size_t length)
	: data_(new T[length]), cur_size_(0), max_size_(length)
{

}


//
// Base_Array (size_t, char)
//
//treat cur_size_ as how many spots are filled by a character
//treat max_size_ as the full length of memory allocated, regardless of how filled it is
//initialize the Base_Array to length and fill with character that is passed as a parameter
template <typename T>
Base_Array <T>::Base_Array(size_t length, T fill)
	: data_(new T[length]), cur_size_(length), max_size_(length)
{
	for (size_t i = 0; i < length; i++) {
		data_[i] = fill;
	}
}

template <typename T>
Base_Array <T>::Base_Array(const Base_Array<T> & arr)
    : data_(new T [arr.max_size_]), cur_size_(arr.cur_size_), max_size_(arr.max_size_)
{
	for (size_t i = 0; i < length; i++) {
		data_[i] = new Array<T>(*(arr.data_[i]));
	}
}

//
// ~Base_Array
//
template <typename T>
Base_Array <T>::~Base_Array(void)
{
	delete[] data_;
}

//
// operator =
//
//delete current data, which is the data whos object invokes this method
//reassign max_size_ & cur_size_ to rhs of operator
//reallocate memory to the new max_size and fill with contents of rhs
//*this returns reference to itself
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
	max_size_ = rhs.max_size_;
	cur_size_ = rhs.cur_size_;
	data_ = new T[max_size_];

	//possibly cause issue when the types are not the same?
	//but maybe the types could be replaced by values of different type?
	for (size_t i = 0; i < cur_size_; i++) {
		data_[i] = rhs.data_[i];
	}

	return *this;
}


template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
	if (index > max_size_ || index < 0) {
		throw std::out_of_range("Invalid Index");
	}
	else {
		return data_[index];
	}
}

//
// operator []
//
//replaced the try with if statement checking if it was greater than max size and less than 0
//re-read the instructions and correctly throw an exception
//since spaces in some Base_Array arent filled or initialized to anything, only search what is filled
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
	if (index > max_size_ || index < 0) {
		throw std::out_of_range("Invalid Index");
	}
	else {
		return data_[index];
	}
}

//
// get
//
//replaced the try with if statement checking if it was greater than max size and less than 0
//re-read the instructions and correctly throw an exception
template <typename T>
T Base_Array <T>::get(size_t index) const
{
	if (index > max_size_ || index < 0) {
		throw std::out_of_range("Invalid Index");
	}
	else {
		return data_[index];
	}
}

//
// set
//
template <typename T>
void Base_Array <T>::set(size_t index, T value)
{
	if (index > max_size_ || index < 0) {
		throw std::out_of_range("Invalid Index");
	}
	else {
		data_[index] = value;
	}
}

template  <typename T>
int Base_Array <T>::find(T value) const
{
	for (size_t i = 0; i < max_size_; i++) {
		if (data_[i] == value) {
			return i;
		}
		else {
			return -1;
		}
	}
}

//
// find (char, size_t)
//
template <typename T>
int Base_Array <T>::find(T val, size_t start) const
{
	if (start > 0 && start < max_size_) {
		for (size_t i = start; i < max_size_; i++) {
			if (data_[i] == val) {
				return i;
			}
		}
	}
	else {
		throw std::out_of_range("Invalid Start Value");
		return -1;
	}
}

//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
	//bool keepgoing = true;
	size_t i = 0;

	if (*this == rhs) {
		return true;
	}

	if (cur_size_ == rhs.cur_size_) {
		while (data_[i] == rhs.data_[i]) {
			i++;
			if (i == cur_size_) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}

}

//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
	if (*this != rhs) {
		return true;
	}

	for (size_t i = 0; i < cur_size_; i++) {
		if (data_[i] != rhs.data_[i] || cur_size_ != rhs.cur_size_) {
			return true;
		}
		else {
			return false;
		}
	}
}

//
// fill
//
template <typename T>
void Base_Array <T>::fill(T value)
{
	for (size_t i = 0; i < max_size_; i++) {
		data_[i] = value;
	}
}

