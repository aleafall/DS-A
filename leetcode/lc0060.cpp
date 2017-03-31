//
// Created by aleafall on 16-10-10.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        int cnt=1;
        for (int i = 1; i <= n; ++i) {
            cnt*=i;
        }
        k%=cnt;
        for (int i = 0; i < n; ++i) {
            s+=i+'1';
        }
        for (int i = 0; i < k; ++i) {
            next_permutation(s.begin(),s.end());
        }
        return s;
    }
};

int main(){
    int cnt=1;
    for (int i = 0; i < 9; ++i) {
        cnt*=(i+1);
    }
    cout<<cnt<<endl;
    return 0;
}