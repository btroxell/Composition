// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//

//default constructor
// initialization section of the constructor.
// Used the new syntax learned from the slides
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
	: Base_Array(void)
{

}

//
// Fixed_Array
//
//copies everything over to this arr
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
	: Base_Array(arr)
{

}

//
// Fixed_Array
//

//? if this is a fixed array taking in an array of size m, then it is no longer a fixed array
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
	: Base_Array(arr)
{

}

//
// Fixed_Array
//

//fills array with the value of fill
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
	: data_(new T [N]), cur_size_(N), max_size_(N)
{
	for (size_t i = 0; i < N; i++) {
		data[i] = fill;
	}
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
	delete[] data_;
}

//
// operator =
//

//copies everything over to the array that uses the assignment operator
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	max_size_ = rhs.max_size_;
	cur_size_ = rhs.cur_size_;
	data_ = rhs.data_;

	return *this;
}

//
// operator =
//

//assigns everything over to the array that uses this operator
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	max_size_ = M;
	cur_size_ = rhs.cur_size_;
	data_ = rhs.data_;

	return *this;
}
