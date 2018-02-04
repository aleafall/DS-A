//
// Created by aleafall on 17-9-25.
//

#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const {
		return false;
	}

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const {
		return 0;
	}

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const {
		vector<NestedInteger> v;
		return v;
	}
};

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
	vector<int> vi;
	int index;
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		index = 0;
		for (auto &item :nestedList) {
			getNumber(item, vi);
		}
	}

	void getNumber(NestedInteger &integer,vector<int> &vi){
		if (integer.isInteger()) {
			vi.push_back(integer.getInteger());
		} else {
			auto ls = integer.getList();
			for (auto &item :ls) {
				getNumber(integer, vi);
			}
		}
	}
	int next() {
		return vi[index++];
	}

	bool hasNext() {
		return index < vi.size();
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
int main() {
	NestedInteger so;

    return 0;
}
