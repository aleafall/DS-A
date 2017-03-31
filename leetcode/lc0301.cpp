//
// Created by aleafall on 16-10-30.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q;
        set<string> st;
        q.push(s);
        bool found=0;
        while (!q.empty()) {
            s=q.front();
            q.pop();
            if (isValid(s)) {
                found=1;
                ans.push_back(s);
            }
            if (found) continue;
            for (size_t i = 0; i < s.size(); ++i) {
                if (s[i] == '(' || s[i] == ')') {
                    string str = s.substr(0, i) + s.substr(i + 1, s.size());
                    if (st.find(str) == st.end()) {
                        q.push(str);
                        st.insert(str);
                    }
                }
            }
        }
        return ans;
    }
    bool isValid(const string &s){
        stack<char> st;
        for (size_t i = 0; i <s.size() ; ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.size() && st.top() == '(') {
                    st.pop();
                } else {
                    return 0;
                }
            }
        }
        return st.empty();
    }
};

int main(){
    Solution *solution=new Solution;
    string s = "(a)())()";
    vector<string> vi = solution->removeInvalidParentheses(s);
    for (size_t i = 0; i <vi.size() ; ++i) {
        cout<<vi[i]<<endl;
    }
    delete solution;
    return 0;
}