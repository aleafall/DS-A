//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()||matrix[0].empty()) {
            return 0;
        }
        int n=(int)matrix.size()*(int)matrix[0].size();
        int ans = binarySearch(0, n-1, matrix, target);
        return ans!=-1;
    }

    int binarySearch(int l,int r,vector<vector<int>> &matrix, int target){
        while (l<=r) {
            int mid=(l+r)/2;
//            cout<<"mid "<<mid<<endl;
            int now=matrix[mid/matrix[0].size()][mid%matrix[0].size()];
//            cout<<"now "<<now<<endl;
            if (now==target) {
                return mid;
            } else if (now > target) {
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> matrix{{1,   3,  5,  7},{10, 11, 16, 20},{23, 30, 34, 50}};
    Solution *solution=new Solution;
    int target=21;
    cout<<solution->searchMatrix(matrix,target)<<endl;
    delete solution;
    return 0;
}
