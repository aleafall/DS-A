//
// Created by aleafall on 16-10-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a[3] = {0};
        for (size_t i = 0; i <nums.size() ; ++i) {
            a[nums[i]]++;
        }
        int cnt=0;
        for (int i = 0; i <3 ; ++i) {
            for (int j = 0; j <a[i] ; ++j) {
                nums[cnt+j]=i;
            }
            cnt += a[i];
        }
    }
};
