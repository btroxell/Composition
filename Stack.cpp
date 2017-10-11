// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
//#include "Stack.h"

template <typename T>
Stack <T>::Stack (void)
	: stack_array_(0), is_empty_(true), e()
{

}

//
// Stack
//
//constructs a stack that uses the copy constructor of array
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
	: stack_array(stack.stack_array_), is_empty_(stack.is_empty_), e()
{

}

//
// ~Stack
//
//deletes top node and should delete the other nodes as well
template <typename T>
Stack <T>::~Stack (void)
{
	
}

//
// push
//works with max_size_ since resize changes max_size_ 
//resizes by 1 and places the element in that index, and any succeeding elements after it
//replicating the functionality of a stack
template <typename T>
void Stack <T>::push (T element)
{

	stack_array_.resize(stack_array_.size()+1);

	stack_array_.set(stack_array_.size()+1, element);


}

//
// pop
//
//simply resizes it to a smaller size to throw away top element
template <typename T>
void Stack <T>::pop (void)
{
	if (is_empty_ == true) {
		throw e;
	}
	else {
		stack_array_.resize(stack_array_.size() - 1);
	}

}

//
// operator =
//
//takes the address/copy of the rhs and returns a reference to itself
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	*this = rhs;

	return *this;
}

//
// clear
//
//deletes all the nodes in the stack
template <typename T>
void Stack <T>::clear (void)
{
	stack_array_.resize(0);
}


