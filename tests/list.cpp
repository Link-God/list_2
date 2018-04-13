#include <catch.hpp>
#include <sstream>

#include "list.hpp"

TEST_CASE("creating_tree")
{
	queue_t<int> list;
	REQUIRE( list.head() == nullptr );
	REQUIRE( list.tail() == nullptr );
	
}

TEST_CASE("pop and push")
{
	queue_t<int> list;
	list.push(1);
	list.push(2);
	int sum = list.pop();
	sum = sum + list.pop();
	REQUIRE( sum == 3 );
	
}

TEST_CASE("throw")
{
	queue_t<int> list;
	REQUIRE_THROWS_AS( list.pop() , std::out_of_range);
	
}

TEST_CASE("copy")
{
	queue_t<int> list;
	list.push(1);
	list.push(2);
	queue_t<int> list2(list);
	int sum = list2.pop();
	sum = sum + list2.pop();
	REQUIRE( sum == 3 );
	
}
TEST_CASE("assignment")
{
	queue_t<int> list;
	list.push(1);
	list.push(2);
	queue_t<int> list2 = list;
	int sum = lis2.pop();
	sum = sum + list2.pop();
	REQUIRE( sum == 3 );
	
}
TEST_CASE("string")
{
	queue_t<string> list;
	list.push("Hello");
	REQUIRE( list.pop() == "Hello" );
	
}
