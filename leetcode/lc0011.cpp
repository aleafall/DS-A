//
// Created by aleafall on 16-11-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0,j=(int)height.size()-1;
        while (i < j) {
            int now = (j - i) * min(height[i], height[j]);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
            ans = max(ans, now);
        }
        return ans;
    }
};