// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Queue.h"

template <typename T>
Queue <T>::Queue(void)
	: size_(0), is_empty(true)
{

}

//
// Queue
//
//similar to stack, except the end node will be pointing to a previous node
//stores the size of the queue passed in and copies all its node data over
//updates all the pointers to point to the previous node added
template <typename T>
Queue <T>::Queue(const Queue & q)
	: queue_array(q.queue_array_), is_empty_(q.is_empty_)
{

}

//
// ~queue
//
//destructor deletes the end node
template <typename T>
Queue <T>::~Queue(void)
{
	~Array();
}

//
// enqueue
//
//adds a node to the end of the queue and makes it prev point to nullptr
//updates the the prev pointer of the one after it to the one that was added
//end node stay the same, only tail node gets updated
template <typename T>
void Queue <T>::enqueue(T element)
{
	T temp_data_ = new T [queue_array_.cur_size+1];
	temp_data_[0] = element;

	for(size_t i=0; i<queue_array_.cur_size+1; i++){
        temp_data_[i+1] = queue_array_.data[i];
	}

	queue_array_.resize(queue_data_.cur_size_);
	queue_array_.data_ = temp_data_;

	queue_array_.cur_size_ += 1;
}

//
// dequeue
//
//removes element at the front of the list, make that prev a nullptr and then release the value
//then update it to point to the node before it
template <typename T>
void Queue <T>::dequeue(void)
{
    if(is_empty == true){
        throw empty_exception.empty_exception();
    }
    else {
        queue_array_.resize(cur_size_-1);
        queue_array_.cur_size_ -= 1;
    }
}

//
// operator =
//
//returns a reference to itself
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	this = &rhs;

	return this;
}

//
// clear
//
//delete all nodes in the queue
template <typename T>
void Queue <T>::clear(void)
{
	queue.resize(0);
}

