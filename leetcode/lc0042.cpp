//
// Created by aleafall on 16-11-9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
	    int left = 0, right = height.size() - 1;
	    int ans = 0, leftMax = 0, rightMax = 0;
	    while (left <= right) {
		    if (height[left] <= height[right]) {
			    if (height[left] >= leftMax) {
				    leftMax = height[left];
			    } else {
				    ans += leftMax - height[left];
			    }
			    ++left;
		    } else {
			    if (height[right] >= rightMax) {
				    rightMax = height[right];
			    } else {
				    ans += rightMax - height[right];
			    }
			    --right;
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
