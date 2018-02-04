//
// Created by aleafall on 17-9-13.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	vector<vector<string>> ans;
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> st;
		for (const auto &item : wordList) {
			st.insert(item);
		}
		vector<string> vs{beginWord};
		DFS(vs, beginWord, endWord, st);
		return ans;
	}

	void DFS(vector<string> &vs,string &nowWord, string &endWord, unordered_set<string> &st) {
		if (nowWord == endWord) {
			if (ans.empty()||ans.front().size()==vs.size()) {
				ans.push_back(vs);
			} else if (ans.front().size() > vs.size()) {
				ans.clear();
				ans.push_back(vs);
			}
			return;
		}
		for (int i = 0; i < nowWord.size(); ++i) {
			char temp = nowWord[i];
			for (char c = 'a'; c <= 'z'; ++c) {
				if (c != temp) {
					nowWord[i] = c;
					if (st.count(nowWord)) {
						vs.push_back(nowWord);
						st.erase(nowWord);
						DFS(vs, nowWord, endWord, st);
						vs.pop_back();
						st.insert(nowWord);
					}
					nowWord[i] = temp;
				}
			}
		}
	}
};

int main() {
    Solution solution;
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList{"hot", "dot", "dog", "lot", "log"};
	auto ans = solution.findLadders(beginWord, endWord, wordList);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
};
