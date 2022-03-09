#include <iostream>
#include <vector>

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
	int simple = std::count(v.begin(), v.end(), target);
	std::cout << "value of simple: " << simple << '\n';



	return 0;
}
