//
// Created by aleafall on 16-11-1.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans((unsigned long) n, vector<int>((unsigned long) n));
        int minR=0,maxR=n,minC=0,maxC=n;
        int nowR=0,nowC=0;
        int index=1;
        bool flag=1;
        while (index <= n*n) {
            if (flag) {
                for (nowC = minC, nowR = minR; nowC < maxC; ++nowC, ++index) {
                    ans[nowR][nowC] = index;
                }
                minR++;
                for (nowR = minR, nowC = maxC - 1; nowR < maxR; ++nowR, ++index) {
                    ans[nowR][nowC] = index;
                }
                maxC--;
                flag=0;
            } else {
                for (nowC = maxC - 1, nowR = maxR - 1; nowC >= minC; --nowC, ++index) {
                    ans[nowR][nowC] = index;
                }
                maxR--;
                for (nowR = maxR - 1, nowC = minC; nowR >= minR; --nowR, ++index) {
                    ans[nowR][nowC] = index;
                }
                minC++;
                flag=1;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> ans;
    Solution *solution=new Solution;
    ans = solution->generateMatrix(3);
    for (size_t i = 0; i <ans.size() ; ++i) {
        for (size_t j = 0; j <ans[0].size() ; ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    delete solution;
    return 0;
}
