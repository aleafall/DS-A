//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> temp;
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        int n= (int) nums.size();
        int len=1;
        for (int i = 0; i < n; ++i) {
            len*=2;
        }
        for (int i = 0; i < len; ++i) {
            int index=i;
            vector<int> now;
            for (int j = 0; j < n; ++j) {
                int t=index%2;
                index/=2;
                if (t) now.push_back(nums[j]);
            }
            sort(now.begin(),now.end());
            temp.insert(now);
        }
        for (auto it=temp.begin();it!=temp.end();++it){
            ans.push_back(*it);
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> ans;
    vector<int> nums{4,4,4,1,4};
    Solution *solution=new Solution;
    ans=solution->subsetsWithDup(nums);
    delete solution;
    cout<<"ans.size() "<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j <ans[i].size() ; ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}