//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        vector<int> ans;
        if (nums.empty()) return nums;
        int m1=nums[0],m2=0;
        int c1=1,c2=0;
        for (int i = 0; i < nums.size(); ++i) {
            if (m1==nums[i]) c1++;
            else if (m2==nums[i]) c2++;
            else if (c1==0){
                m1=nums[i];
                c1=1;
            } else if (c2==0){
                m2=nums[i];
                c2=1;
            } else {
                --c1;
                --c2;
            }
        }
        c1=c2=0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]==m1) c1++;
            else if (nums[i]==m2) c2++;
        }
        if (c1>(int)nums.size()/3) ans.push_back(m1);
        if (c2>(int)nums.size()/3) ans.push_back(m2);
        return ans;
    }
};

int main(){
    vector<int> nums{1};
    Solution *solution=new Solution;
    vector<int> ans(solution->majorityElement(nums));
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<endl;
    }
    delete solution;
    return 0;
}
