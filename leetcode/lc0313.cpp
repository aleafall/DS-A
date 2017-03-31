//
// Created by aleafall on 16-10-18.
//

#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        size_t len=primes.size();
        vector<int> times(len,0);
        vector<int> uglys((unsigned long) n, INT_MAX);
        uglys[0]=1;
        for (int i = 0; i < n; ++i) {
            for (size_t j = 0; j < len; ++j) {
                uglys[i]=min(uglys[i],uglys[times[j]]*primes[j]);
            }
            for (size_t j = 0; j < len; ++j) {
                if (uglys[i]==uglys[times[j]]*primes[j]) times[j]++;
            }
        }
        return uglys[n-1];
    }
};

int main() {
    int n = 100000;
    Solution *solution = new Solution;
    vector<int> primes{
            7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167, 179, 181, 199,
            211, 229, 233, 239, 241, 251};
    cout << solution->nthSuperUglyNumber(n, primes) << endl;
    delete solution;
    return 0;
}
