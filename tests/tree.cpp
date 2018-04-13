#include <catch.hpp>
#include <sstream>

#include "list.hpp"

TEST_CASE("creating_tree")
{
	tree_t<int> tree;
	REQUIRE( tree.root() == nullptr );
}
