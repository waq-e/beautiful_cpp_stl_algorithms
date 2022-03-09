#include <iostream>
#include <vector>
#include <string>
#include <map>

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
	// Section 4 Section 4 Section 4 Section 4 Section 4 Section 4 Section 4 Section 4 Section 4
	// =========================================================================================
	// count how many entries in collection meet a (any) condition (ie, filter):
	// repeating what is done above, on a map
	std::map<int, int> monthLengths{{1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},
									{10,31},{11,30},{12,31}};
	int longMonths = std::count_if(begin(monthLengths), end(monthLengths),
								   [](auto elem) { return elem.second == 31; });
	std::cout << "longMonths = " << longMonths << '\n';
	// Section 5 Section 5 Section 5 Section 5 Section 5 Section 5 Section 5 Section 5 Section 5
	// =========================================================================================
	// Why counting?
	//      Are all elements odd, equal to zero, or high priority?
	//      Are any of the elements odd, equal to zero, etc.
	//      Are none of the elements odd, ...
	std::vector<int> v2{ 2,7,1,6,2,-2,4,0 };
	bool allof = std::all_of(begin(v2), end(v2),
	                         [](auto elem) { return elem % 2 != 0; });
	bool noneof = std::none_of(begin(v2), end(v2),
	                         [](auto elem) { return elem % 2 != 0; });
	bool anyof = std::any_of(begin(v2), end(v2),
	                         [](auto elem) { return elem % 2 != 0; });
	// Section 6 Section 6 Section 6 Section 6 Section 6 Section 6 Section 6 Section 6 Section 6
	// =========================================================================================



	return 0;
}
