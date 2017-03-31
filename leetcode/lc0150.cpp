//
// Created by aleafall on 16-10-13.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<long long> st;
        long long num = 0;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i].size()==0) continue;
            if (isNum(tokens[i], num)) {
//                cout<<"push "<<num<<endl;
                st.push(num);
            } else if (isOp(tokens[i])) {
                long long n1 = st.top();
                st.pop();
                long long n2 = st.top();
                st.pop();
                if (n2==0&&tokens[i][0]=='/'){
//                    cout<<"here\n";
                }
                long long ans = cal(n2, n1, tokens[i][0]);
                st.push(ans);
            }
        }
        if (st.size())
        return (int)st.top();
        else return 0;
    }

    bool isNum(const string &s, long long &num) {
        num = 0;
        int flag = 1;
        int i = 0;
        if (s[i] == '-' && s.size() > 1) {
            i++;
            flag = -1;
        }
        for (; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + s[i] - '0';
            else return 0;
        }
        num *= flag;
        return 1;
    }

    bool isOp(const string &s) {
        if (s.size() != 1) return 0;
        return 1;
    }

    long long cal(long long n1, long long n2, char c) {
        switch (c) {
            case '+':
                return n1 + n2;
            case '-':
                return n1 - n2;
            case '*':
                return n1 * n2;
            case '/':
                return n1 / n2;
            default:
                break;
        }
        return 0;
    }

};

int main() {
    vector<string> vi{"-78", "-33", "196", "+", "-19", "-", "115", "+", "-", "-99", "/", "-18", "8", "*", "-86", "-",
                      "-", "16", "/", "26", "-14", "-", "-", "47", "-", "101", "-", "163", "*", "143", "-", "0", "-",
                      "171", "+", "120", "*", "-60", "+", "156", "/", "173", "/", "-24", "11", "+", "21", "/", "*",
                      "44", "*", "180", "70", "-40", "-", "*", "86", "132", "-84", "+", "*", "-", "38", "/", "/", "21",
                      "28", "/", "+", "83", "/", "-31", "156", "-", "+", "28", "/", "95", "-", "120", "+", "8", "*",
                      "90", "-", "-94", "*", "-73", "/", "-62", "/", "93", "*", "196", "-", "-59", "+", "187", "-",
                      "143", "/", "-79", "-89", "+", "-"};
    Solution *solution = new Solution;
    cout << solution->evalRPN(vi) << endl;
    delete solution;
    return 0;
}