//
// Created by aleafall on 16-10-19.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int a[n+1]={0};
        a[0] = a[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                a[i]+=a[j]*a[i-j-1];
            }
        }
        return a[n];
    }
};

int main() {
    Solution *solution = new Solution;
    int n = 3;
    for (int i = 0; i <= 3; ++i) {
        cout << solution->numTrees(i) << endl;
    }
    delete solution;
    return 0;
}
