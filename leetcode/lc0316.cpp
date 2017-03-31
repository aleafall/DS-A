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
	    int hashTable[256] = {0};
	    bool vis[256] = {0};
        string ans;
        for (size_t i = 0; i <s.size() ; ++i) {
	        hashTable[s[i]]++;
        }
	    ans += '0';
	    for (int i = 0; i < s.size(); ++i) {
		    hashTable[s[i]]--;
		    if (vis[s[i]]) {
			    continue;
		    } else {
			    while (s[i] < ans.back() && hashTable[ans.back()]) {
				    vis[ans.back()] = 0;
				    ans.pop_back();
			    }
			    ans += s[i];
			    vis[s[i]] = 1;
		    }
	    }
	    return ans.substr(1);
    }
};
