//
// Created by aleafall on 17-2-28.
//

#include <iostream>

using namespace std;

class TrieNode{
public:
	bool isString;
	TrieNode *next[26];

	TrieNode(){
		for (int i = 0; i < 26; ++i) {
			next[i] = NULL;
		}
		isString = 0;
	}
protected:
private:
};
class WordDictionary {
public:
	TrieNode *root;
	/** Initialize your data structure here. */
	WordDictionary() {
		root=new TrieNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); ++i) {
			if (!p->next[word[i] - 'a']) {
				p->next[word[i] - 'a'] = new TrieNode();
			}
			p = p->next[word[i] - 'a'];
		}
		p->isString = 1;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(word, 0, root);
	}
	bool search(const string &word,int index,   TrieNode *now){
		if (!now) {
			return 0;
		}
		if (index == word.size()) {
			return now->isString;
		}
		if (word[index] == '.') {
			for (int i = 0; i < 26; ++i) {
				if (now->next[i]) {
					if (search(word, index + 1, now->next[i])) {
						return 1;
					}
				}
			}
		} else if (now->next[word[index]-'a']) {
			return search(word, index + 1, now->next[word[index] - 'a']);
		}
		return 0;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
