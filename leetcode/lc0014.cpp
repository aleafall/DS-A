//
// Created by aleafall on 16-10-5.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans = "";
        if (strs.size() == 0) return ans;
        int len = strs[0].size();
        for (int i = 0; i < strs.size(); i++) {
            if (i) {
                if (strs[i].size() < len) len = strs[i].size();
            }
        }
        bool flag = 1;
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) ans += strs[0][i];
            else break;
        }
        return ans;
    }
};
