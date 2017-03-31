//
// Created by aleafall on 16-10-24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = (int) matrix.size() * (int) matrix[0].size();
        vector<int> vi;
        for (size_t i = 0; i <matrix.size() ; ++i) {
            for (size_t j = 0; j <matrix[0].size() ; ++j) {
                vi.push_back(matrix[i][j]);
            }
        }
        nth_element(vi.begin(), vi.begin() + k - 1, vi.end());
        return vi[k - 1];
    }
};

int main() {
    vector<vector<int>> vi{{1,4,7,11,15}, {2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution *solution = new Solution;
    int k = 5;
    cout << solution->kthSmallest(vi, k) << endl;
    delete solution;
    return 0;
}