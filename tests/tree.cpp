#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating_tree")
{
	tree_t tree;
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
	tree_t tree;
	std::string out {
		"----3\n"
		"--2\n"
		"----1\n"
	};
	tree.no_consol_Operator('+', 2);
	tree.no_consol_Operator('+', 1);
	tree.no_consol_Operator('+', 3);
	
	std::ostringstream stream;
	
	tree.no_consol_Operator('?', 5, stream);
	REQUIRE(stream.str() == "false");
	
	tree.no_consol_Operator('?', 3, stream);
	REQUIRE(stream.str() == "true");
	
	tree.no_consol_Operator('=', NULL , stream);
	REQUIRE(stream.str() == out);
}
TEST_CASE("insert_and_print") 
{
	tree_t tree;
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
	tree_t tree;
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
