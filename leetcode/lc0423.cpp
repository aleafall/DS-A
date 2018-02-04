//
// Created by aleafall on 17-9-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string originalDigits(string s) {
		unordered_map<char, int> mp;
		int size = s.size();
		for (auto &&item :s) {
			mp[item]++;
		}
		string ans;
		vector<string> nums{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
		for (int i = 0; i < nums.size(); ++i) {
			while (check(nums[i], mp)) {
				for (auto &&item :nums[i]) {
					mp[item]--;
				}
				ans += (i + '0');
			}
		}
		return ans;
	}

	bool check(string &s, unordered_map<char, int> &mp) {
		for (auto &&item :s) {
			if (mp[item] <= 0) {
				return 0;
			}
		}
		return 1;
	}
};
