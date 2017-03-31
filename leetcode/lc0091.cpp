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
        string str;
        for (auto item:s) {
            if (item >= '1' && item <= '9') {
                str += item;
            }
        }
        s=str;
        if (s.empty()) {
            return 0;
        }
        DFS(s, 0);
        return ans;
    }
    void DFS(string &s,int index){
        if (index >= s.size()) {
            ans++;
            return;
        }
        DFS(s, index + 1);
        if (index+1<s.size()&& atoi(s.substr(index, index + 2).c_str()) <= 26) {
            DFS(s, index + 2);
        }
    }
};
