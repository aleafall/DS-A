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
	    /*
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
        */
	    vector<int> ans(1, 1);
	    int i2 = 0, i3 = 0, i5 = 0, m2, m3, m5,Min;
	    while (ans.size() < n) {
		    m2 = ans[i2] * 2, m3 = ans[i3] * m3, m5 = ans[i5] * 5;
		    Min = min(m2, min(m3, m5));
		    if (Min == m2) {
			    i2++;
		    } else if (Min == m3) {
			    i3++;
		    } else {
			    i5++;
		    }
		    ans.push_back(Min);
	    }
	    return ans.back();
    }
};

int main() {
    int n = 1407;
    Solution *solution = new Solution;
    cout << solution->nthUglyNumber(n) << endl;
    delete solution;
    return 0;
}
