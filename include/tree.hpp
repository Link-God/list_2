#include <sstream>
#include<iostream>
#include<string>

template < typename T >
class list_t
{
	struct node_t{
		node_t * next;
		T value;
	};
	node_t * head;
	node_t * tail;
public:
	list_t()
	{
		head = nullptr;
		tail = nullptr;
	}
	~list_t()
	{
		if (head != nullptr) {
			node_t *temp = head;
			while(head)
			temp = head;
			head = head->next;
			delete temp;
		}
	}
	void push(T value)
	{
		node_t * node = new node_t;
		node->value = value;
		node->next = nullptr;
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
	}
	void pop()
	{
		if (head != nullptr) {
			node_t *temp = head;
			head = head->next;
			delete temp;
		}
		else {
			throw std::out_of_range("Invalid range");
		}
	}

};
