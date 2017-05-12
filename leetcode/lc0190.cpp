//
// Created by aleafall on 16-10-19.
//

#include <iostream>

using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
	    uint32_t ans = 0;
	    for (int i = 0; i < 32; ++i) {
		    ans <<= 1;
		    ans |= (n & 1);
		    n >>= 1;
	    }
	    return ans;
    }
};

int main(){
    Solution *solution=new Solution;
    uint32_t n=43261596;
    cout<<solution->reverseBits(n)<<endl;
    delete solution;
	uint32_t x = 0;
	for (int i = 0; i < 32; ++i) {
		cout << "x " << x << endl;
		x <<= 1;
	}
    return 0;
}