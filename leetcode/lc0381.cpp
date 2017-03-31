//
// Created by aleafall on 17-2-28.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedCollection {
public:
	vector<int> nums;
	unordered_map<int, vector<int>> ump;

	/** Initialize your data structure here. */
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool flag = 1;
		if (ump.count(val)) {
			flag = 0;
		}
		nums.push_back(val);
		ump[val].push_back((int) nums.size() - 1);
		return flag;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (!ump.count(val) || ump[val].empty()) {
			return 0;
		}
		int index = ump[val].back();
		int lastNumIndex = (int) nums.size() - 1;
		swap(nums[index], nums.back());
		for (int i = 0; i < ump[nums[index]].size(); ++i) {
			if (ump[nums[index]][i] == lastNumIndex) {
				ump[nums[index]][i] = index;
				break;
			}
		}

		ump[val].pop_back();
		nums.pop_back();
		return 1;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		if (nums.empty()) {
			return 0;
		}
		return nums[rand() % (int) nums.size()];
	}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */