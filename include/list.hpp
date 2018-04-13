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
	{
		head_ = nullptr;
		tail_ = nullptr;
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
		node_t * temp = new node_t;
		temp = other->head_;
		node_t * temp2 = new node_t;
		temp2 = head_;
		while (temp != other.tail_) {
			temp2->value = tepm->value;
			temp2->next = nullptr;
			temp2 = temp2->next;
			temp = tepm->next;
		}
		temp2->value = tepm->value;
		temp2->next = nullptr;
		tail_ = temp2;
		delete temp; delete temp2;
	}
	queue_t<T> & operator =(queue_t<T> const & other)
	{

		if (this != &other) {
			if (head_ != nullptr) {
				node_t *temp = head_;
				while (head_) {
					temp = head_;
					head_ = head_->next;
					delete temp;
				}
			}
			node_t * temp = new node_t;
			temp = other->head_;
			node_t * temp2 = new node_t;
			temp2 = head_;
			while (temp != other.tail_) {
				temp2->value = tepm->value;
				temp2->next = nullptr;
				temp2 = temp2->next;
				temp = tepm->next;
			}
			temp2->value = tepm->value;
			temp2->next = nullptr;
			tail_ = temp2;
			delete temp; delete temp2;
		}
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
		if (head_ != nullptr) {
			T a = head->value;
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
