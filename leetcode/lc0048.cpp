//
// Created by aleafall on 16-11-2.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=(int)matrix.size()-1;
        for (int i = 0,temp=0; i <=n/2 ; ++i) {
            for (int j = i; j < n - i; ++j) {
                temp = matrix[j][n - i];
                matrix[j][n - i] = matrix[i][j];
                matrix[i][j] = matrix[n - j][i];
                matrix[n - j][i] = matrix[n - i][n - j];
                matrix[n - i][n - j]=temp;
            }
        }
    }
};
