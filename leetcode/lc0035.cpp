//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = (int) (nums.size() - 1);
        int mid = 0;
        while(left <= right){
            mid = left+(right-left)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        //没找到
        return right+1;
    }
};

int main(){
    Solution *solution=new Solution;
    int target=0;
    vector<int> vi{1,3,5,6};
    cout << solution->searchInsert(vi, target);
    delete solution;
    return 0;
}