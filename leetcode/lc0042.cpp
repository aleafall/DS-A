//
// Created by aleafall on 16-11-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) {
            return 0;
        }
        int ans=0,left=0,right=(int)height.size() -1;
        int leftWall = height[left], rightWall = height[right];
        while (left < right) {
            if (leftWall <= rightWall) {
                ++left;
                if (height[left] <= leftWall) {
                    ans += leftWall - height[left];
                } else {
                    leftWall = height[left];
                }
            } else {
                --right;
                if (height[right] <= rightWall) {
                    ans += rightWall - height[right];
                } else {
                    rightWall = height[right];
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution *solution=new Solution;
    vector<int> vi{};
    cout<<solution->trap(vi)<<endl;
    delete solution;
    return 0;
}
