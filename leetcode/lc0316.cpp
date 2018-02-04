//
// Created by aleafall on 16-11-18.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
	    int cnt[26] = {0};
	    bool vis[26] = {0};
	    string ans = "0";
	    for (auto &&item :s) {
		    cnt[item - 'a']++;
	    }
	    for (auto &&item :s) {
		    --cnt[item - 'a'];
		    if (vis[item - 'a']) {
			    continue;
		    }
		    while (item < ans.back() && vis[ans.back() - 'a']) {
			    vis[ans.back() - 'a'] = 0;
			    ans.pop_back();
		    }
		    ans += item;
		    vis[item - 'a'] = 1;
	    }
	    return ans.substr(1);
    }
};

int main() {
	Solution solution;
	string s = "cbacdcbc";
	cout << solution.removeDuplicateLetters(s) << endl;
    return 0;
}
