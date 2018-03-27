#include <catch.hpp>
#include <sstream>

#include "tree.hpp"

TEST_CASE("creating tree")
{
	tree_t tree;
	REQUIRE( tree.root() == nullptr );
}

TEST_CASE("conlose")
{
	// необходимый код для выполнение консольных команд 
	/*
		std::ostringstream ostream;
		Operator(ostream , tree );
	*/
	REQUIRE( 0 == 0 );
}

TEST_CASE("insert_and_print") {
	tree_t  tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	
	std::string out {
		"----4\n"
		"--2\n"
		"----2\n"
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
