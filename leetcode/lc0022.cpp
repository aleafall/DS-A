//
// Created by aleafall on 16-11-16.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return ans;
        }
        string now="(";
        DFS(now, n, 1, 0);
        return ans;
    }

    void DFS(string now, int n, int left, int right){
        if (now.length() == 2 * n) {
            ans.push_back(now);
            return;
        }
        if (left < n) {
            DFS(now + "(", n, left + 1, right);
        }
        if (right + 1 <= left) {
            DFS(now + ")", n, left, right + 1);
        }
    }
};
