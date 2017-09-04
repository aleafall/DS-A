//
// Created by t-xiuyan on 8/19/2017.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPossible(vector<int> &nums) {
		vector<int> vi(nums.size() + 1, 0);
		for (auto &&item :nums) {
			vi[item]++;
		}

	}
};

int main() {

	return 0;
}
