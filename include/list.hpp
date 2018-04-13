#include <sstream>
#include<iostream>
#include<string>

template < typename T >
class queue_t
{
	struct node_t {
		node_t * next;
		T value;
	};
	node_t * head_;
	node_t * tail_;
public:
	queue_t()
		: head_ (nullptr)
		, tail_ (nullptr)	
	{
		;
	}
	~queue_t()
	{
		if (head_ != nullptr) {
			node_t *temp = head_;
			while (head_)
				temp = head_;
			head_ = head_->next;
			delete temp;
		}
	}
	node_t * head() const
	{
		return  head_;
	}
	node_t * tail() const
	{
		return  tail_;
	}

	queue_t(queue_t<T> const & other)
	{
		for (auto it = other.head_; it; it = it->next)
		{
			push(it->value);
		}

	}
	queue_t<T> & operator =(queue_t<T> const & other)
	{
		if (&other == this) {
			return *this;
		}
		this->~queue_t();
		queue_t new_queue(other);
		this = &new_queue;
		return *this;
	}
	void push(T value)
	{
		node_t * node = new node_t;
		node->value = value;
		node->next = nullptr;
		if (head_ == nullptr) {
			head_ = node;
			tail_ = node;
		}
		else {
			tail_->next = node;
			tail_ = node;
		}
	}
	T pop()
	{
		T a ;
		if (head_ != nullptr) {
			a = head_->value;
			node_t *temp = head_;
			head_ = head_->next;
			delete temp;
		}
		else {
			throw std::out_of_range("Invalid range");
		}
		return a ;
	}

};
