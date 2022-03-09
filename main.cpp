#include <iostream>
#include <vector>
#include <string>

// Headers you should know:
//      <algorithm>
//      <vector> <array> <list> <stack> <map> <queue>
//      <string>
//      ..maybe <iterator>
//      ..maybe <utility> <tuple>

int main() {

	// Section 1 Section 1 Section 1 Section 1 Section 1 Section 1 Section 1 Section 1 Section 1
	// =========================================================================================
	// count how many entries in collection have the target value (2)
	std::vector<int> v{1, 2, 5, 3, 2, 4, 5, 1, 3, 2};
	int twos{0};
	int const target{2};
	for (size_t i{0}; i < v.size(); i++) {
		if (v[i] == target) twos++;
	}
	std::cout << "value of twos: " << twos << '\n';
	// using <algorithm> to do above
	twos = std::count(v.begin(), v.end(), target);
	// twos = std::count(begin(v), end(v), target);
	std::cout << "value of twos: " << twos << '\n';
	// Section 2 Section 2 Section 2 Section 2 Section 2 Section 2 Section 2 Section 2 Section 2
	// =========================================================================================
	//      Member                  |               Nonmember
	// v.begin(), v.end()           | begin(v), end(v)
	//                              |
	// works for all collections    | works for all collections + c-style arrays
	//                              |
	//                              | you can write a free function for a collection
	//                              | without member begin() and end()
	//                              |
	//                              | safest choice and good habit

	// Section 3 Section 3 Section 3 Section 3 Section 3 Section 3 Section 3 Section 3 Section 3
	// =========================================================================================
	// count how many entries in collection meet a (any) condition (ie, filter):
	int odds{0};
	for (auto elem: v) {
		if (elem % 2 != 0) odds++;
	}
	std::cout << "value of odds: " << odds << '\n';
	// using <algorithm> to do above
	odds = std::count_if(begin(v), end(v),
						 [](auto elem) { return elem % 2 != 0;});
	std::cout << "value of odds: " << odds << '\n';


	return 0;
}
