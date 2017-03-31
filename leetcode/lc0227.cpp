//
// Created by aleafall on 16-10-14.
//

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    map<char, int> Rank;
    struct Node {
        int num;
        char op;
        bool flag;
    } node;
    stack<Node> st;
    queue<Node> q;
    int calculate(string s) {
        Rank['+'] = Rank['-'] = 1;
        Rank['*'] = Rank['/'] = 2;
        string str;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]!=' ') str+=s[i];
        }
        int index=0,num=0;
        while (index<str.size()){
            if (str[index]>='0'&&str[index]<='9'){
                for (; index<str.size()&&str[index]>='0'&&str[index]<='9';++index){
                    num=num*10+str[index]-'0';
                }
                node.flag=1;
                node.num=num;
                q.push(node);
                num=0;
            } else {
                while (!st.empty()&&Rank[str[index]]<=Rank[st.top().op]){
                    q.push(st.top());
                    st.pop();
                }
                node.flag=0;
                node.op=str[index];
                st.push(node);
                index++;
            }
        }
        while (st.size()){
            q.push(st.top());
            st.pop();
        }
        while (q.size()){
            if (q.front().flag){
                st.push(q.front());
            } else{
                int n2=st.top().num;
                st.pop();
                int n1=st.top().num;
                st.pop();
                node.flag=1;
                switch (q.front().op){
                    case '+':
                        node.num=n1+n2;
                        break;
                    case '-':
                        node.num=n1-n2;
                        break;
                    case '*':
                        node.num=n1*n2;
                        break;
                    case '/':
                        node.num=n1/n2;
                        break;
                    default:
                        break;
                }
                st.push(node);
            }
            q.pop();
        }
        return st.top().num;
    }
};

int main(){
    Solution *solution=new Solution;
    string s=" 3+5 / 2 ";
    cout<<solution->calculate(s)<<endl;
    delete solution;
    return 0;
}
