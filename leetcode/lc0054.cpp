//
// Created by aleafall on 16-10-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int minR=0,maxR = (int) matrix.size(), minC=0,maxC = (int) matrix[0].size();
        int nowR=0,nowC=0;
        int n=maxR*maxC;
        bool flag=1;
        while (n) {
            if (flag) {
                for (nowC=minC,nowR=minR; nowC <maxC ; ++nowC,--n) {
                    ans.push_back(matrix[nowR][nowC]);
                }
                minR++;
                for (nowR=minR,nowC=maxC-1; nowR < maxR; ++nowR,--n) {
                    ans.push_back(matrix[nowR][nowC]);
                }
                maxC--;
                flag = 0;
            } else {
                for (nowC=maxC-1,nowR=maxR-1; nowC >= minC; --nowC,--n) {
                    ans.push_back(matrix[nowR][nowC]);
                }
                maxR--;
                for (nowR = maxR - 1,nowC=minC; nowR >= minR; --nowR,--n) {
                    ans.push_back(matrix[nowR][nowC]);
                }
                minC++;
                flag=1;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> vi{{1, 2, 3},
                           {4, 5, 6},
                           {7, 8, 9}};
    Solution *solution=new Solution;
    vector<int> ans = solution->spiralOrder(vi);
    for (size_t i = 0; i <ans.size() ; ++i) {
        cout<<ans[i]<<endl;
    }
    delete solution;
    return 0;
}