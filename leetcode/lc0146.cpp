//
// Created by aleafall on 17-3-16.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
public:
	unordered_map<int, list<pair<int, int>>::iterator> ump;
	list<pair<int, int>> values;
	int size;

	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (ump.count(key)) {
			auto now = *ump[key];
			int value = now.second;
			values.erase(ump[key]);
			values.push_front(now);
			ump[key] = values.begin();
			return value;
		}
		return -1;
	}

	void put(int key, int value) {
		if (ump.count(key)) {
			values.erase(ump[key]);
		}
		values.push_front(make_pair(key, value));
		ump[key] = values.begin();
		if (values.size() > size) {
			pair<int, int> end = (pair<int, int> &&) values.back();
			ump.erase(end.first);
			values.pop_back();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
