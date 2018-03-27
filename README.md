[![Build Status](https://travis-ci.org/Link-God/tree.svg?branch=master)](https://travis-ci.org/Link-God/tree)
```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose
```

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
