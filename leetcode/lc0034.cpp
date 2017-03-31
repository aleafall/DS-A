//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = binarySearch(nums, target);
        if (pos == -1) {
            return vector<int>{-1, -1};
        }
        int i=pos,j=pos;
        while (i > 0 && nums[i-1] == nums[pos]) {
            i--;
        }
        while (j < nums.size() - 1 && nums[j+1] == nums[pos]) {
            j++;
        }
        return vector<int>{i,j};
    }

    int binarySearch(vector<int> &nums, int target){
        int l = 0, r = (int) nums.size()-1;
        while (l <= r) {
            int mid=(l+r)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r=mid-1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> vi{2},ans;
    Solution *solution=new Solution;
    ans=solution->searchRange(vi,2);
    for (auto i:ans) {
        cout<<i<<endl;
    }
    delete solution;
    return 0;
}