//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (size_t i = 0; i <matrix.size() ; ++i) {
            if (binarySearch(0, (int) matrix[i].size() - 1, matrix[i], target) != -1) {
                return 1;
            }
        }
        return 0;
    }
    int binarySearch(int l,int r,vector<int> &vi,int target){
        while (l <= r) {
            int mid = (l + r)/2;
            if (vi[mid] == target) {
                return mid;
            } else if (vi[mid]>target){
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return -1;
    }
};
