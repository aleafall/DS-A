//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if (total & 1) {
            return Kth_element(nums1, 0, nums2, 0, total / 2 + 1);
        } else {
            return (Kth_element(nums1, 0, nums2, 0, total / 2) + Kth_element(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
        }
    }

    double Kth_element(vector<int> &v1, int a_begin, vector<int> &v2, int b_begin, int k){
        if (a_begin>v1.size()) {
            return v2[b_begin + k - 1];
        }
        if (b_begin > v2.size()) {
	        return v1[a_begin + k - 1];
        }
	    if (k == 1) {
		    return min(v1[a_begin], v2[b_begin]);
	    }
	    int a_key = a_begin + k / 2 - 1 >= v1.size() ? INT32_MAX : v1[a_begin + k / 2 - 1];
	    int b_key = b_begin + k / 2 - 1 >= v2.size() ? INT32_MAX : v2[b_begi + k / 2 - 1];
	    if (a_key > b_key) {
		    return Kth_element(v1, a_begin, v2, b_begin + k / 2, k - k / 2);
	    } else {
		    return Kth_element(v1, a_begin + k / 2, v2, b_begin, k - k / 2);
	    }
    }
};
