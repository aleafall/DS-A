<<<<<<< HEAD
//
// Created by aleafall on 17-9-16.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		vector<vector<int>> vi;
		for (int i = 0; i < nums.size(); ++i) {
			bool put = 0;
			for (int j = 0; j < vi.size(); ++j) {
				if (nums[i] == vi[j].back() + 1) {
					vi[j].push_back(nums[i]);
					put = 1;
					break;
				}
			}
			if (!put) {
				vi.emplace_back(vector<int>{nums[i]});
			}
		}
		for (auto &&item :vi) {
			if (item.size() < 3) {
				return 0;
			}
		}
		return 1;
	}
};
=======
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
>>>>>>> 758190852492f055a2a6122324716c916e0711bb
