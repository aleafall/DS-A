//
// Created by aleafall on 16-10-10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int index=0;
        while (index<nums.size()){
            if (nums[index]>0&&nums[index] <= (int) nums.size() && nums[index] != index + 1&&
                nums[nums[index]-1]!=nums[index]){
                swap(nums[index],nums[nums[index]-1]);
            } else ++index;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1){
                return i + 1;
            }
        }
        return (int)nums.size()+1;
    }

    ~Solution() {
        cout << "destory" << endl;
    }
};

int main() {
    cout << "test" << endl;
    Solution *solution = new Solution;
    vector<int> vi{1, 4, 5, 6, 3, 7};
    cout << solution->firstMissingPositive(vi) << endl;
    return 0;
}
