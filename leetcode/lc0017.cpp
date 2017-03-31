//
// Created by aleafall on 16-10-6.
//
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> str{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return ans;
        }
        string now;
        DFS(digits, now, 0);
        return ans;
    }
    void DFS(string &digits, string now,int index){
        if (now.size() == digits.size()) {
            ans.push_back(now);
            return;
        }
        int k=digits[index]-'2';
        for (size_t i = 0; i <str[k].size() ; ++i) {
            DFS(digits, now + str[k][i], index + 1);
        }
    }
};
int main(){
	
}
