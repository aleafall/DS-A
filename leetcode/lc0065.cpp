//
// Created by aleafall on 16-10-23.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) {
            return 0;
        }
        string str;
        int index=-1;
        for (auto i:s) {
            if (i != ' ') {
                str += i;
            }
        }
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == 'E' || str[i] == 'e') {
                index= (int) i;
            }
        }
        if (index != -1) {
            return isSigleNumber(str.substr(0, index)) && isSigleNumber(str.substr( index + 1, str.size()));
        } else {
            return isSigleNumber(str);
        }
        return 1;
    }

    bool isSigleNumber(basic_string<char, char_traits<char>, allocator<char>> s){
        if (s.size() && (s[0] == '-' || s[0] == '+')) {
            s.erase(s.begin());
        }
        string str;
        int cnt=0;
        for (size_t i = 0; i <s.size() ; ++i) {
            if (s[i] != '.') {
                str+=s[i];
            } else {
//                if (i==0)
//                    return 0;
                cnt++;
                if (cnt > 1) {
                    return 0;
                }
            }
        }
        if (str.empty()) {
            return 0;
        }
        for (size_t i = 0; i <str.size() ; ++i) {
            if (str[i] < '0' || str[i] > '9') {
                return 0;
            }
        }
        return 1;
    }
};
int main(){
    string s=".4";
    Solution *solution=new Solution;
    cout<<solution->isNumber(s)<<endl;
    delete solution;
    return 0;
}

