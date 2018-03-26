#include <iostream>
#include <sstream>

class tree_t
{
private:
	struct node_t {
		node_t * left;
		node_t * right;
		int value;
	};
private:
	node_t * root_;
public:
	tree_t()
	{
		root_= nullptr;
	}
	tree_t(tree_t const & other)
	{
		root_ = other.root_;
	}
	
	~tree_t()
	{
		// delete root
	}
	void insert(int value)
	{
		node_t * node = new node_t;
		node->value = value;
		node->left = nullptr;
		node->right = nullptr;

		if (root_ == nullptr) {
			root_ = node;
		}
		else {
			node_t * time = root_;
			while (time != nullptr){
				if (value >= time->value){
					if (time->right != nullptr) {
						time = time->right;
					}
					else {
						time = node;
					}
				}
				else{
					if (time->left != nullptr) {
						time = time->left;
					}
					else {
						time = node;
					}

				}
			}
		}
	}
	bool find(int value) const
	{
		if (root_->value == value) {
			return true;
		}
		else {
			node_t * time = root_;
			while (time != nullptr){
				if (value >= time->value) {
					if (time->right != nullptr && time->right->value!=value) {
						time = time->right;
					}
					else {
						return true;
					}
				}
				else {
					if (time->left != nullptr && time->left->value != value) {
						time = time->left;
					}
					else {
						return true;
					}
				}
			}
			return false;
		}
	}
	void print(std::ostream & stream) const
	{
		
	}
};
