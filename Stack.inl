// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return stack_array_.max_size();
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	try {
		return stack_array_.get(stack_array_.max_size());
	}
	catch (empty_exception &ex) {
		std::cout << "empty exception: " << std::endl;
	}
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	return is_empty_;
}
