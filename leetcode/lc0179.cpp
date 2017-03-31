//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        string ans;
        for (int i = 0; i < nums.size(); ++i) {
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(),temp.end(),cmp);
        for (int i = 0; i < temp.size(); ++i) {
            ans+=temp[i];
        }
        while (ans.size()&&ans[0]=='0') ans.erase(ans.begin());
        return ans;
    }

    static bool cmp(string a,string b){
        return a+b>b+a;
    }
};

int main(){
    vector<int> nums{3, 30, 34, 5, 9};
    Solution *solution=new Solution;
    string ans=solution->largestNumber(nums);
    delete solution;
    cout<<ans<<endl;
    return 0;
}