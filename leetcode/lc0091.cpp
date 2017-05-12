//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int ans=0;

    int numDecodings(string s) {
        /*string str;
        for (auto item:s) {
            if (item >= '0' && item <= '9') {
                str += item;
            }
        }
        s=str;
        if (s.empty()) {
            return 0;
        }
        DFS(s, 0);
        return ans;*/
        if (s.empty() || s.front() == '0') {
            return 0;
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                dp[i] = 0;
            }
            if (s[i - 1] == '1' || (s[i - 1] <= '2' && s[i] <= '6')) {
                dp[i + 1] = dp[i] + dp[i - 1];
            } else {
                dp[i + 1] = dp[i];
            }
        }
        return dp[s.size()];
    }
    void DFS(string &s,int index){
        if (index >= s.size()) {
            ans++;
            return;
        }
        if (s[index] == '0') {
            return;
        }
        DFS(s, index + 1);
        if (index+1<s.size()&& atoi(s.substr(index, 2).c_str()) <= 26) {
            DFS(s, index + 2);
        }
    }
};
