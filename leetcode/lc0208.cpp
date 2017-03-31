//
// Created by aleafall on 17-2-28.
//

#include <iostream>

using namespace std;

class TrieNode {
public:
	TrieNode(){
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
		}
	}

	TrieNode *next[26];
	bool isString;
};
class Trie {
public:
	TrieNode *root;
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!p->next[word[i] - 'a']) {
				p->next[word[i]-'a']=new TrieNode();
			}
			p = p->next[word[i] - 'a'];
		}
		p->isString = 1;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!p->next[word[i] - 'a']) {
				return 0;
			}
			p = p->next[word[i] - 'a'];
		}
		return p && p->isString;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (int i = 0; i < prefix.size(); ++i) {
			p = p->next[prefix[i] - 'a'];
			if (!p) {
				return 0;
			}
		}
		return 1;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
