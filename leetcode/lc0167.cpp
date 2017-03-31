//
// Created by aleafall on 16-10-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=(int)numbers.size()-1;
        while (i<j){
            if (numbers[i]+numbers[j]>target) --j;
            else if (numbers[i]+numbers[j]<target) ++i;
            else break;
        }
        vector<int> ans{i+1,j+1};
        return ans;
    }
};