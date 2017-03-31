//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		if (beginWord == endWord) {
			return 1;
		}
		int ans = 2;
		unordered_set<string> ust;
		queue<string> q;
		for (int i = 0; i < wordList.size(); ++i) {
			ust.insert(wordList[i]);
		}
		q.push(beginWord);
		int len = beginWord.size();
		ust.erase(beginWord);
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				string word = q.front();
				q.pop();
				for (int j = 0; j < len; ++j) {
					char temp = word[j];
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == temp) {
							continue;
						}
						word[j] = c;
						if (ust.count(word)) {
							if (word == endWord) {
								return ans;
							}
							q.push(word);
							ust.erase(word);
						}
					}
					word[j] = temp;
				}
			}
			++ans;
		}
		return 0;
	}
};
