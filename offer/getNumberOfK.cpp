//
// Created by aleafall on 17-2-24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data ,int k) {
		int ans = 0;
		if (data.empty()) {
			return 0;
		}
		auto lowwer = lower_bound(data.begin(), data.end(), k);
		while (lowwer != data.end() && *lowwer == k) {
			++ans, lowwer++;
		}
		return ans;
	}
};

int main(){
	Solution solution;
	vector<int> vi{1, 2, 2, 2, 3};
	cout << solution.GetNumberOfK(vi, 4) << endl;
}
