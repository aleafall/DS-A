//
// Created by aleafall on 17-9-19.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class MapSum {
	unordered_map<string,int> mp;
	struct TrieNode {
		char c;
		TrieNode *next[26];
		bool isString;
		TrieNode(){
			for (auto &item : next) {
				item = NULL;
			}
			isString = 0;
		}
	};
	TrieNode *root;
public:
	/** Initialize your data structure here. */
	MapSum() {
		root = new TrieNode();
	}

	void insert(string key, int val) {
		if (!mp.count(key)) {
			auto node = root;
			for (int i = 0; i < key.size(); ++i) {
				if (!node->next[key[i] - 'a']) {
					node->next[key[i] - 'a']=new TrieNode();
				}
				node = node->next[key[i] - 'a'];
			}
			node->isString = 1;
		}
		mp[key] = val;
	}

	int sum(string prefix) {
		int ans = 0;
		auto node = root;
		for (int i = 0; i < prefix.size(); ++i) {
			if (!node->next[prefix[i] - 'a']) {
				return ans;
			}
			node = node->next[prefix[i] - 'a'];
		}
		query(prefix, ans, node);
		return ans;
	}
	void query(string &prefix,int &ans,TrieNode *node){
		ans += node->isString ? mp[prefix] : 0;
		for (int i = 0; i < 26; ++i) {
			if (node->next[i]) {
				prefix += i + 'a';
				query(prefix, ans, node->next[i]);
				prefix.pop_back();
			}
		}
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main() {
	cout << (1 << 32) << endl;
	return 0;
}