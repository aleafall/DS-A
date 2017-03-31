//
// Created by aleafall on 16-10-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
};

int main(){
    Solution *solution=new Solution;
    vector<int> vi{3, 2, 2, 3};
    int len = solution->removeElement(vi, 1);
    for (int i = 0; i <len ; ++i) {
        cout<<vi[i]<<endl;
    }
    delete solution;
    return 0;
}
