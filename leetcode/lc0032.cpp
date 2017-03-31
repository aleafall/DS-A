//
// Created by aleafall on 16-11-9.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int lastIndex=0,ans=0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push((const int &) i);
            } else {
                if (st.empty()) {
                    lastIndex= (int) (i + 1);
                } else {
                    st.pop();
                    if (st.empty()) {
                        ans = max(ans, (const int &) (i - lastIndex + 1));
                    } else {
                        //?
                        ans = max(ans, (const int &) (i - st.top()));
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution *solution=new Solution;
    string s = "()(()";
    cout << solution->longestValidParentheses(s)<<endl;
    delete solution;
    return 0;
}
