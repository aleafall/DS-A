//
// Created by aleafall on 16-10-30.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (size_t i = 0; i <s.size() ; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                switch (s[i]) {
                    case ')':
                        if (st.size() && st.top() == '(') {
                            st.pop();
                        } else { return 0;}
                        break;
                    case '}':
                        if (st.size() && st.top() == '{') {
                            st.pop();
                        } else {
                            return 0;
                        }
                        break;
                    case ']':
                        if (st.size() && st.top() == '[') {
                            st.pop();
                        } else {
                            return 0;
                        }
                    default:
                        break;
                }
            }
        }
        return st.empty();
    }
};

int main(){
    string s = "(]";
    Solution *solution=new Solution;
    cout<<solution->isValid(s)<<endl;
    delete solution;
    return 0;
}