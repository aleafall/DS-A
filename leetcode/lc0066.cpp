//
// Created by aleafall on 16-10-5.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        vector<int> ans;
        int carry = 0;
        for (int i = 0; i < digits.size(); ++i) {
            int plus = i == 0 ? 1 : 0;
            int now = (plus + digits[i] + carry) % 10;
            carry = (plus + digits[i] + carry) / 10;
            ans.push_back(now);
        }
        if (carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        if (ans.size() == 0) ans.push_back(1);
        return ans;
    }
};

int main() {
    vector<int> vi = {9};
    Solution *solution = new Solution;
    vector<int> ans = solution->plusOne(vi);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
