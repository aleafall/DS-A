//
// Created by aleafall on 16-10-18.
//
//todo
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if (n & 1) {
            ans=x;
            n--;
        } else ans=1.0;

    }
};

int main() {
    Solution *solution = new Solution;
    double x = 34.00515;
    int n = -3;
    cout << solution->myPow(x, n) << endl;
    delete solution;
    return 0;
}
