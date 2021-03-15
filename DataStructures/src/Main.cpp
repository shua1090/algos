#include <iostream>
#include "HashMap.h"

/* REQUIREMENTS
* hash struct 
	overload ()
	return int
	accept `const K&` and `int bucketCount` as param
*/

template <class T>
void print(const T& item) {
	std::cout << item << std::endl;
}

struct StrIntHash {
	int operator()(const std::string& key, int bucketCount) const {
		if (key.length() == 0) return 0;
		return static_cast<int>(key[0]) % bucketCount;
	}
};

int main() {
	HashMap<std::string, int, StrIntHash> map(4);
	map.insert("hello", 5);
	map.insert("ho", 10);
	map.insert("green", 3);

	print(map.get("hello"));
	print(map.get("ho"));
	map.set("ho", 15);
	print(map["ho"]);
}
