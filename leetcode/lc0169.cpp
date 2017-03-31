//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],Max=0;
        map<int,int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp.find(nums[i])!=mp.end()) mp[nums[i]]++;
            else mp[nums[i]]=1;
        }
        for(auto it=mp.begin();it!=mp.end();++it){
            if (it->second>Max){
                Max=it->second;
                ans=it->first;
            }
        }
        return ans;
    }
};

