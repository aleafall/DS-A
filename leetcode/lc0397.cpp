//
// Created by aleafall on 16-10-25.
//

#include <iostream>

using namespace std;

class Solution {
public:
    long long ans=INT64_MAX;
    int integerReplacement(int n) {
        long long t=n;
        DFS(t, 0);
        return (int) ans;
    }
    void DFS(long long n,int step){
        if (n == 1) {
            if (step < ans) {
                ans=step;
            }
            return;
        }
        if (n & 1) {
            DFS(n + 1, step + 1);
            DFS(n - 1, step + 1);
        } else {
            DFS(n / 2, step + 1);
        }
    }
};

int main() {
    int n = 2147483647;
    Solution *solution = new Solution;
    cout << solution->integerReplacement(n) << endl;
    delete solution;
    return 0;
}