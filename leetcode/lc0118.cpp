//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vi;
        for (int i = 0; i < numRows; ++i) {
            vector<int> now((unsigned long) (i + 1),1);
            for (int j = 1; j <= i/2; ++j) {
                now[j] = now[i-j] = vi[i - 1][j - 1] + vi[i - 1][j];
            }
            vi.push_back(now);
        }
        return vi;
    }
};

int main(){
    Solution *solution=new Solution;
    int n=10;
    vector<vector<int>> vi = solution->generate(n);
    for (size_t i = 0; i <vi.size() ; ++i) {
        for (size_t j = 0; j <vi[i].size() ; ++j) {
            cout<<vi[i][j]<<" ";
        }
        cout<<endl;
    }
    delete solution;
    return 0;
}