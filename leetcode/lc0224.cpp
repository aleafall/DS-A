//
// Created by aleafall on 16-10-13.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    struct Node {
        int num;
        char op;
        bool flag;
        Node():flag(0){}
    } node;
    stack<Node> st;
    queue<Node> q;
    map<char, int> Rank;

    int calculate(string s) {
        string str;
        Rank['('] = Rank[')'] = 0;
        Rank['+'] = Rank['-'] = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') str += s[i];
        }
        int index = 0, num = 0;
        while (index < str.size()) {
            if (str[index] >= '0' && str[index] <= '9') {
                for (; index < str.size() && str[index] >= '0' && str[index] <= '9'; ++index) {
                    num = num * 10 + str[index] - '0';
                }
                node.num = num;
                node.flag = 1;
                q.push(node);
                num = 0;
            } else if (str[index] == '+' || str[index] == '-') {
                while (!st.empty()&&Rank[str[index]]<=Rank[st.top().op]){
                    q.push(st.top());
                    st.pop();
                }
                node.flag = 0;
                node.op = str[index];
                st.push(node);
                index++;
            } else if (str[index] == '(') {
                node.op = str[index];
                st.push(node);
                index++;
            } else {
                while (!st.empty() && st.top().op != '(') {
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                index++;
            }
        }
        while (st.size()) {
            q.push(st.top());
            st.pop();
        }
        while (q.size()){
            if (q.front().flag) {
                st.push(q.front());
            }
            else {
                int n1 = st.top().num;
                st.pop();
                int n2 = st.top().num;
                st.pop();
                if (q.front().op == '+') {
                    node.num = n1 + n2;
                } else {
                    node.num = (n2 - n1);
                }
                node.flag = 1;
                st.push(node);
            }
            q.pop();
        }
        return st.top().num;
    }
};

int main() {
    string s = " 2-1 + 2 ";
    Solution *solution = new Solution;
    cout << solution->calculate(s) << endl;
    delete solution;
    return 0;
}
