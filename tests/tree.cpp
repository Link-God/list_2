#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating_tree")
{
	tree_t<int> tree;
	REQUIRE( tree.root() == nullptr );
}

		//   Console
// необходимый код для выполнение консольных команд 
//
//int main()
//{
//  tree_t tree;
//  std::ostringstream ostream;
//  Operator(ostream , tree );
//  std ::cin.get();
//  return 0;
//}

TEST_CASE("No_console")
{
	tree_t<int> tree;
	std::string out {
		"----3\n"
		"--2\n"
		"----1\n"
	};
	tree.no_consol_Operator('+', 2);
	tree.no_consol_Operator('+', 1);
	tree.no_consol_Operator('+', 3);
	
	std::ostringstream stream;
	std::ostringstream stream2;
	std::ostringstream stream3;
	
	tree.no_consol_Operator('?', 5, stream);
	REQUIRE(stream.str() == "false");
	
	tree.no_consol_Operator('?', 3, stream2);
	REQUIRE(stream2.str() == "true");
	
	tree.no_consol_Operator('=', 0 , stream3);
	REQUIRE(stream3.str() == out);
}
TEST_CASE("insert_and_print") 
{
	tree_t<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	
	std::string out {
		"----3\n"
		"--2\n"
		"----1\n"
	};
	std::ostringstream ostream;
	tree.print(ostream , tree.root());
	REQUIRE(ostream.str() == out);
}

TEST_CASE("find")
{
	tree_t<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(6);
	tree.insert(9);
	tree.insert(7);
	
	REQUIRE(tree.find(5) == false);
	REQUIRE(tree.find(8) == false);
	REQUIRE(tree.find(9) == true);	
	REQUIRE(tree.find(7) == true);
}

TEST_CASE("equal")
{
	tree_t<int> tree1;
	tree_t<int> tree2 {2 , 1 , 3 , 6 , 9 , 7 };
	tree1.insert(2);
	tree1.insert(1);
	tree1.insert(3);
	tree1.insert(6);
	tree1.insert(9);
	tree1.insert(7);
	bool q ;
	if(tree1 == tree2){
		q= true;
	}
	else{ q =false ;}
	
	REQUIRE(q== true);
}

TEST_CASE("remove")
{
	
	tree_t<int> tree {2 , 1 , 3 , 6 , 9 , 7 };
	bool one = tree.remove(1);
	bool two = tree.remove(10);
	
	REQUIRE(one);
	REQUIRE(!two);
}
