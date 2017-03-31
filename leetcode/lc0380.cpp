//
// Created by aleafall on 17-2-28.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class RandomizedSet {
	unordered_set<int> ust;

public:

	/** Initialize your data structure here. */
	RandomizedSet() {
		ust.clear();
		srand((unsigned int) time(NULL));
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (ust.find(val) != ust.end()) {
			return 0;
		}
		ust.insert(val);
		return 1;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (ust.find(val) == ust.end()) {
			return 0;
		}
		ust.erase(val);
		return 1;
	}

	/** Get a random element from the set. */
	int getRandom() {
		int index = rand() % (int) ust.size();
		for (auto it = ust.begin(); it != ust.end(); ++it, --index) {
			if (!index) {
				return *it;
			}
		}
		return 0;
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
