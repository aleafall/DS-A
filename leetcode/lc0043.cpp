//
// Created by aleafall on 16-10-5.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        const int maxn = num1.size() + num2.size() + 5;
        int a[maxn] = {0};
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num2.size() > num1.size()) num1.swap(num2);
        for (int i = 0; i < num2.size(); ++i) {
            add(maxn, a, num1, num2, i);
        }
        int index = maxn - 1;
        while (index >= 0 && a[index] == 0) index--;
        for (int i = index; i >= 0; --i) {
            ans += a[i] + '0';
        }
        if (ans.size() == 0) ans += '0';
        return ans;
    }

    void add(const int maxn, int a[], const string &num1, const string &num2, int n) {
        int carry = 0, n1 = num2[n] - '0';
        int b[num1.size() + 5] = {0};
        for (int i = 0; i < num1.size(); ++i) {
            int n2 = num1[i] - '0';
            int now = (n1 * n2 + carry) % 10;
            carry = (n1 * n2 + carry) / 10;
            b[i] = now;
        }
        if (carry) b[num1.size()] = carry;
        carry = 0;
        for (int i = 0; i + n < maxn; ++i) {
            if (i < num1.size() + 1) {
                int now = (a[i + n] + b[i] + carry) % 10;
                carry = (a[i + n] + b[i] + carry) / 10;
                a[i + n] = now;
            } else {
                int now = (a[i + n] + carry) % 10;
                carry = (a[i] + carry) / 10;
                a[i + n] = now;
            }
        }

    }
};

int main() {
    string s1 = "9";
    string s2 = "9";
    Solution *solution = new Solution;
    string ans = solution->multiply(s1, s2);
    cout << ans << endl;
    return 0;
}