//
// Created by aleafall on 17-9-16.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MagicDictionary {
public:
	unordered_set<string> st;
	/** Initialize your data structure here. */
	MagicDictionary() {

	}

	/** Build a dictionary through a list of words */
	void buildDict(vector<string> dict) {
		for (auto &&item :dict) {
			st.insert(item);
		}
	}

	/** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
	bool search(string word) {
		for (int i = 0; i < word.size(); ++i) {
			char temp = word[i];
			for (char c = 'a'; c <= 'z'; ++c) {
				if (c != temp) {
					word[i] = c;
					if (st.count(word)) {
						return 1;
					}
				}
			}
			word[i] = temp;
		}
		return 0;
	}
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
