//
// Created by aleafall on 16-12-6.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size()<=2){
            return s;
        }
        string ans;
        for (int i = 1; i < s.size() - 1; ++i) {
            int j=i-1,k=i+1;
            while(j>=0&&k<s.size()&&s[j]==s[k]){
                --j;
                ++k;
            }
            if (2 * (k - i) - 1 > ans.size()) {
                ans=s.substr(j+1,k);
            }
            j=i-1,k=i;
            while(j>=0&&k<s.size()&&s[j]==s[k]){
                --j;
                ++k;
            }
            if(k-j-1>s.size()){
                ans=s.substr(j+1,k);
            }
        }
        return ans;
    }
};
