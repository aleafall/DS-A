//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long y=x;
        bool flag=0;
        if (y < 0) {
            y=-y;
            flag=1;
        }
        string str = to_string(y);
//        cout<<str<<endl;
        std::reverse(str.begin(), str.end());
//        cout<<str<<endl;
        long long ans =0;
        for (size_t i = 0; i <str.size() ; ++i) {
            ans = ans * 10 + str[i] - '0';
        }
//        cout<<"ans "<<ans<<endl;
        if(flag) ans=-ans;
        if (ans > INT32_MAX || ans < INT32_MIN) {
            ans=0;
        }
        return (int) ans;
    }
};

int main(){
    Solution *solution=new Solution;
    cout<<solution->reverse(1534236469)<<endl;
    delete solution;
    return 0;
}