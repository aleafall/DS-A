//
// Created by aleafall on 16-10-29.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int len= (int) s.size();
        for (int i = 0; i <len/2 ; ++i) {
            swap(s[i], s[len - i - 1]);
        }
        return s;
    }
};

int main(){
    Solution *solution=new Solution;
    string s = "Marge let's \"went.\" I await news telegram.";
    cout << solution->reverseString(s)<<endl;
    delete solution;
    return 0;
}