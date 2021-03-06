#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Employee.h"

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
	std::vector<int> v3{ 2, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
	std::string s{"Hello I am a sentence"};
	// find the first zero in the collection
	auto result = find(begin(v3), end(v3), 0);
	int weLookedFor = *result;  // result is a point to that element (found it)
	std::cout << "weLookedFor " << weLookedFor << '\n';
	result = std::find(result, end(v3), 2);  // search from 0 found forward
	if (result != end(v3)) {  // can only dereference result if element found!  otherwise result invalid pointer!
		weLookedFor = *result;
	}
	auto letter = std::find(begin(s), end(s), 'a');
	char a = *letter;
	std::cout << "a = " << a << '\n';
	// Section 7 Section 7 Section 7 Section 7 Section 7 Section 7 Section 7 Section 7 Section 7
	// =========================================================================================
	// find_if_not      find first element not matching
	// find_first_of    find first occurence of two elements
	// search           find a sequence
	// find_end         search for last
	// search_n         search for n occurances of
	// adjacent_find    find to consecutive occurances of






	std::vector<int> vsort{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
	auto vcopy = vsort;
	sort(begin(vcopy), end(vcopy));  // -9 -6 -2 0 0 0 1 1 2 3 4 7 9
	vcopy = vsort;
	sort(begin(vcopy), end(vcopy),
	     [](int elem1, int elem2) { return elem1 > elem2; });  // 9 7 4 3 2 1 1 0 0 0 -2 -6 -9
	vcopy = vsort;
	sort(begin(vcopy), end(vcopy),     // -9 9 7 -6 4 3 -2 2 1 1 0 0 0
	     [](int elem1, int elem2) { return abs(elem1) > abs(elem2); });


	std::vector<Employee> staff{
				{"Kate", "Gregory", 1000 },
				{"Obvious", "Artificial", 2000 },
				{"Fake", "Name", 1000 },
				{"Alan", "Turing", 2000 },
				{"Grace", "Hopper", 2000 },
				{"Anita", "Borg", 2000 }
	};

	// below works only if operator< defined for Employee
	//std::sort(begin(staff), end(staff));
	std::sort(begin(staff), end(staff),
	          [](Employee e1, Employee e2)
	          { return e1.getSalaray() < e2.getSalaray(); });
	for ( auto emp : staff ) {
		std::cout << emp.getSortingName() << "\t" << emp.getSalaray() << '\n';
	}

	std::cout << "\n\n";
	std::sort(begin(staff), end(staff),
	          [](Employee e1, Employee e2)
	          { return e1.getSortingName() < e2.getSortingName(); });
	for ( auto emp : staff ) {
		std::cout << emp.getSortingName() << "\t" << emp.getSalaray() << '\n';
	}

	std::cout << "\n\n";
	std::sort(begin(staff), end(staff),
	          [](Employee e1, Employee e2)
	          { return e1.getSortingName() < e2.getSortingName(); });
	std::stable_sort(begin(staff), end(staff),
	                 [](Employee e1, Employee e2)
	                 { return e1.getSalaray() < e2.getSalaray(); });
	for ( auto emp : staff ) {
		std::cout << emp.getSortingName() << "\t" << emp.getSalaray() << '\n';
	}

	// left off on video 20160630210634_4  Beautiful C++ STL Algorithms

	return 0;
}
