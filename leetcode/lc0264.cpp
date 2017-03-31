//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt = 0;
        set<long long> st;
        st.insert(1);
        int a[3]={2,3,5};
        long long cur=0;
        while (cnt<n){
            cur=*st.begin();
            st.erase(st.begin());
            for (int i = 0; i < 3; ++i) {
                st.insert(cur*a[i]);
            }
            cnt++;
        }
        return (int)cur;
    }
};

int main() {
    int n = 1407;
    Solution *solution = new Solution;
    cout << solution->nthUglyNumber(n) << endl;
    delete solution;
    return 0;
}
