//
// Created by aleafall on 16-10-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
       rowIndex++;
        vector<int> pre((unsigned long) rowIndex, 1), now((unsigned long) rowIndex, 1);
        for (int i = 0; i < rowIndex; ++i) {
            for (int j = 1; j <= i/2; ++j) {
                now[j] = now[i - j] = pre[j - 1] + pre[j];
            }
            pre=now;
        }
        return now;
    }
};

int main(){
    Solution *solution=new Solution;
    int n=3;
    vector<int> vi = solution->getRow(n);
    for (size_t i = 0; i <vi.size() ; ++i) {
        cout<<vi[i]<<" ";
    }
    cout<<endl;
    delete solution;
    return 0;
}