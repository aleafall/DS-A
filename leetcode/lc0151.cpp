//
// Created by aleafall on 16-10-15.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        string str;
        vector<string> vs;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]!=' ') str+=s[i];
            if (s[i]==' '&&str.size()){
                vs.push_back(str);
                str="";
            }
        }
        if (!str.empty()) vs.push_back(str);
        s.clear();
        for (int i = (int)vs.size()-1; i >= 0 ; --i) {
            s+=vs[i];
            if (i) s+=" ";
        }
    }
};

int main() {
    string s = "  a   b  ";
    Solution *solution = new Solution;
    solution->reverseWords(s);
    delete solution;
    cout << s << endl;
    return 0;
}