//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, k, p;
int Max = -1;
vector<int> ans;
void DFS(vector<int> &vi, int index, int now, int left) {
    if (index == k) {
        if (left == 0) {
            int temp = 0;
            for (int i = 0; i < vi.size(); ++i) {
                temp += vi[i];
            }
            if (temp > Max) {
                Max = temp;
                ans = vi;
            }
        }
        return;
    }
    if (left <= 0) {
        return;
    }
    vi[index] = now;
    int temp = 1;
    for (int i = 0; i < p; ++i) {
        temp *= now;
    }
    left -= temp;
    for (int i = now; i >0 ; --i) {
        DFS(vi, index + 1, i, left);
    }
}

int main() {
    cin >> n >> k >> p;
    int begin = (int) sqrt(1.0 * n);
    vector<int> vi(k);
    for (int i = begin; i >0; --i) {
        DFS(vi, 0, i, n);
    }
    if (ans.empty()) {
        printf("Impossible\n");
    } else {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); ++i) {
            if (i < ans.size() - 1) {
                printf("%d^%d + ", ans[i], p);
            } else {
                printf("%d^%d\n", ans[i], p);
            }
        }
    }
    return 0;
}

