[![Build Status](https://travis-ci.org/Link-God/tree.svg?branch=master)](https://travis-ci.org/Link-God/tree)
```
cmake -H. -B_builds -DBUILD_TESTS=ON
cmake --build _builds
cmake --build _builds --target test -- ARGS=--verbose

```
