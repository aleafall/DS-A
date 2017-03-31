//
// Created by aleafall on 16-11-17.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int ans=0;
    int uniquePaths(int m, int n) {
        int s[m][n] = {0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    s[i][j]=1;
                } else {
                    s[i][j] = s[i - 1][j] + s[i][j - 1];
                }
            }
        }
        return s[m - 1][n - 1];
    }
};

int main(){
    Solution solution;
    cout<<solution.uniquePaths(23,12)<<endl;
    return 0;
}