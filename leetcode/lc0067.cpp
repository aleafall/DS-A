//
// Created by aleafall on 16-10-5.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int i, carry = 0;
        for (i = 0; i < a.size() || i < b.size(); ++i) {
            int n1 = 0, n2 = 0;
            if (i < a.size())
                n1 = a[i] - '0';
            if (i < b.size()) n2 = b[i] - '0';
            int now = (n1 + n2 + carry) % 2;
            carry = (n1 + n2 + carry) / 2;
            ans += now + '0';
        }
        if (carry) ans += carry + '0';
        reverse(ans.begin(), ans.end());
        if (ans.size() == 0) ans += '0';
        return ans;
    }
};
