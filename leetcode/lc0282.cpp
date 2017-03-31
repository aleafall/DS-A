//
// Created by aleafall on 16-10-14.
//
//todo
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
    }
};

int main() {
    string s = "00";
    int target = 0;
    Solution *solution = new Solution;
    auto ans = solution->addOperators(s, target);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    delete solution;
    return 0;
}
