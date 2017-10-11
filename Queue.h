//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#include <exception>

template <typename T>
class Queue
{
public:

	///type definition of type
	typedef T type;

	///default constructor
	Queue(void);

	///copy constructor
	Queue(const Queue & q);

	///destructor
	~Queue(void);

	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception(void)
			: std::exception() { }
	};

	/*
	* Assignment operator
	*
	*@param[in] rhs right side of the operator
	*@return reference to self
	*/
	const Queue & operator = (const Queue & rhs);

	/*
	* put new element on the queue and will be inserted at the end
	* and be the FIFO
	*
	*/
	void enqueue(T element);

	/*
	*removes element at the front of the list
	*throws empty exception if empty
	*
	*/
	void dequeue(void);

	/*
	* test to see if queue is empty where true means its empty
	* false means it is not empty
	*
	*/
	bool is_empty(void) const;

	/*
	* returns the size of the queue
	*
	*
	*/
	size_t size(void) const;

	/*
	* removes all the elements in the array
	*
	*
	*/
	void clear(void);

private:

	Array<T> queue_array_;

	bool is_empty_;

};

#include "Queue.inl"


