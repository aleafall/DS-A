//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            vector<string> vs;
            string now;
            int begin=0,end=0;
            while (end < ans.size()) {
                while (end < ans.size() && ans[begin] == ans[end]) {
                    ++end;
                }

            }
        }
    }
};
