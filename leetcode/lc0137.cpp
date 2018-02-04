//
// Created by t-xiuyan on 6/24/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0, twos = 0;
		for(int i = 0; i < nums.size(); i++){
			ones = (ones ^ nums[i]) & ~twos;
			twos = (twos ^ nums[i]) & ~ones;
			cout << ones << " " << twos << endl;
		}
		return ones;
	}
};

int main() {
    Solution solution;
	vector<int> vi{1, 2, 1, 1};
	cout << solution.singleNumber(vi) << endl;
    return 0;
}
