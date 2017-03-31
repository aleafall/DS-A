//
// Created by aleafall on 16-10-23.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        long long ans=0;
        int flag=1;
        while (str.size()&&str[0]==' ') {
            str.erase(str.begin());
        }
        if (str[0] == '-') {
            flag=-1;
            str.erase(str.begin());
        } else if (str[0]=='+'){
            str.erase(str.begin());
        }
        for (size_t i = 0; i <str.size()&&str[i]>='0'&&str[i]<='9' ; ++i) {
            ans = ans * 10 + str[i] - '0';
            if (ans*flag > INT32_MAX) {
                ans=INT32_MAX;
                return (int) ans;
            }
            if (ans*flag < INT32_MIN) {
                ans=INT32_MIN;
                return (int) ans;
            }
        }
        return (int) ans*flag;
    }
};

int main(){
    string s="-";
    Solution *solution=new Solution;
    cout<<solution->myAtoi(s)<<endl;
    delete solution;
    return 0;
}