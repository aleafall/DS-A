//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        if (n<=9)
            return n;
        long long now = 9;
        int digits= (int) to_string(now).size();
        while (now*digits+(digits-1)*now/10 < n) {
            now*=10;
            digits++;
        }
        long long temp=now/10;
        while (temp){
            --digits;
            n-=digits*temp;
            temp/=10;
        }
        long long i=now/9;
        int len= (int) to_string(i).size();
        while (n-len>0){
            n-=len;
            i++;
        }
        return to_string(i)[n-1]-'0';
    }
};

int main() {
    int n = 1000000000;
//    n=77777777;
    Solution *solution = new Solution;
    cout << solution->findNthDigit(n) << endl;
    delete solution;
    return 0;
}