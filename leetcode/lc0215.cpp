//
// Created by aleafall on 16-10-17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return Kth_elem(nums,0,(int)nums.size()-1,(int)nums.size()-k);
    }
    int Kth_elem(vector<int> &nums,int low,int high,int k){
        swap(nums[low],nums[(low+high)/2]);
        int pivot=nums[low];
        int low_temp=low,high_temp=high;
        while (low<high){
            while (low<high&&nums[high]>pivot) high--;
            nums[low]=nums[high];
            while (low<high&&nums[low]<=pivot) low++;
            nums[high]=nums[low];
            nums[low]=pivot;
        }
        if (low==k) return nums[low];
        if (low>k) return Kth_elem(nums,low_temp,low-1,k);
        else return Kth_elem(nums,low+1,high_temp,k);
    }
};

int main(){
    vector<int> nums{3,2,1,5,6,4};
    Solution *solution=new Solution;
    cout<<solution->findKthLargest(nums,2)<<endl;
    delete solution;
    return 0;
}