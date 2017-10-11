// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include <iostream>

//
// Array
//
// initialization section of the constructor.

template <typename T>
Array <T>::Array (void)
	: Base_Array(void)
{

}

//
// Array (size_t)
//
// Used the new syntax learned from the slides

//treat cur_size_ as how many spots are filled by a character
//treat max_size_ as the full length of memory allocated, regardless of how filled it is
//initialize the array to length
template <typename T>
Array <T>::Array (size_t length)
	: Base_Array(length)
{

}

//
// Array (size_t, char)
//
//treat cur_size_ as how many spots are filled by a character
//treat max_size_ as the full length of memory allocated, regardless of how filled it is
//initialize the array to length and fill with character that is passed as a parameter
template <typename T>
Array <T>::Array (size_t length, T fill)
	: Base_Array(length, fill)
{

}

//
// Array (const Array &)
//
//store incoming array variables to this array's variables
//iterate through to store new array data into the new array's data_ array
template <typename T>
Array <T>::Array (const Array & arr)
	: Base_Array(arr)
{

}


//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}


//
// resize
//

template <typename T>
void Array <T>::resize (size_t new_size)
{
	T * temp_data = new T[new_size];
	if (new_size < cur_size_) {
		for (size_t i = 0; i < new_size; i++) {
			temp_data[i] = data_[i];
		}
	}
	else if (new_size > max_size_) {
		for (size_t i = 0; i < new_size; i++) {
			temp_data[i] = data_[i];
		}
	}
	else if(new_size < 0){
        std::out_of_range("Invalid Index");
	}
	
	data_ = new T[new_size];

	for (size_t i = 0; i < new_size; i++) {
		data_[i] = temp_data[i];
	}

	max_size_ = new_size;
	delete[] temp_data;
}

