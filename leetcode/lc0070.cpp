//
// Created by aleafall on 16-10-29.
//

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long ans=0;
    int *a;
    int climbStairs(int n) {
        a = new int[n+1];
        fill(a, a + n+1, -1);
        a[1]=1,a[2]=2;
        int now = f(n);
        return now;
    }
    int f(int n){
        if (n <= 0) {
            return 1;
        }
        if (n == 1 || n == 2) {
            return n;
        }
        if (a[n] != -1) {
            return a[n];
        }
        a[n] = f(n - 1) + f(n - 2);
        return a[n];
    }
};

int main(){
    Solution *solution=new Solution;
    int n=38;
    cout<<solution->climbStairs(n)<<endl;
    delete solution;
    return 0;
}
