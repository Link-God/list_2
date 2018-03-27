#include <sstream>
#include<iostream>
#include<string>

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
	void del(node_t * node)
	{	
		if ( !(node) ) {
			if (node->left) del (node->left);
			if (node->right) del (node->right);
		}
		delete node;
	}
	~tree_t()
	{
			del(root_);
			//root_ = nullptr;
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
						time->right = node;
						return;
					}
				}
				else{
					if (time->left != nullptr) {
						time = time->left;
					}
					else {
						time->left = node;
						return;
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
	
	node_t * root()
	{
		return  root_;
	}
	void print(std::ostream & stream ,  node_t * node , size_t i = 1) const
	{
		if (node->right) {
			i++;
			print(stream ,node->right, i);
			i--;
		}
		for (size_t k = 0; k < i; k++) {
			stream << "--";
		}
			stream << node->value << std::endl;
		if (node->left) {
			i++;
			print(stream ,node->left, i);
			i--;
		}
	}
};

bool read(char & op, int & value , bool & fail)
{
	
	std::string line;
	getline(std::cin, line);
	std::istringstream stream(line);
	if (stream >> op) {
		if ( (op == '+' && stream >> value) || (op == '?' && stream >> value)) {
			return true;
		}
		else if (op == '=' ) {
			return true;
		}
		else if(op == 'q') {
			return false;
		}
	}
	fail = true;
	return false;

}
void Operator(std ::ostringstream &stream , tree_t & tree)
{
	
	char op;
	int value;
	bool fail=false;
	while (read(op, value, fail)) {
		if (op == '=') {
			tree.print(stream, tree.root(), 1);
			std::cout << stream.str();
		}
		else {
			if (op == '+') tree.insert(value);
			if (op == '?') tree.find(value);
		}
	}
	if (fail) std::cerr << "fail";
}
