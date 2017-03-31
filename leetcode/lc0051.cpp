//
// Created by aleafall on 16-11-16.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<int> vi(n);
        queen(vi, 0);
        return ans;
    }

    void queen(vector<int> &vi, int c) {
        if (c == vi.size()) {
            vector<string> vs(vi.size(), string(vi.size(), '.'));
            for (int i = 0; i < vi.size(); ++i) {
                vs[i][vi[i]] = 'Q';
            }
            ans.push_back(vs);
            return;
        }
        for (vi[c] = 0; vi[c] < vi.size(); ++vi[c]) {
            if (safe(vi, c)) {
                queen(vi, c + 1);
            }
        }
    }

    bool safe(vector<int> &vi, int c) {
        for (size_t i = 0; i < c; ++i) {
            if (vi[c] == vi[i] || abs(vi[c] - vi[i]) == abs(c - i)) {
                return 0;
            }
        }
        return 1;
    }
};

int ans = 0;
int upperlim = (1 << 8) - 1;

void test(int row, int ld, int rd) {
    int pos, p;
    if (row != upperlim) {
        pos = upperlim & (~(row | ld | rd));
        while (pos) {
            p = pos & (~pos + 1);
            pos -= p;
            test(row | p, (ld | p) << 1, (rd | p) >> 1);
        }
    } else {
        ans++;
    }
}

int main() {
    test(0, 0, 0);
    cout << ans << endl;
    return 0;
}