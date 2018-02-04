//
// Created by aleafall on 17-10-22.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> ans;
		if (input.empty()) {
			return ans;
		}
		for (int i = 0; i < input.size(); ++i) {
			if (ispunct(input[i])) {
				for (auto &&a:diffWaysToCompute(input.substr(0, i))) {
					for (auto &&b:diffWaysToCompute(input.substr(i + 1))) {
						ans.push_back(input[i] == '+' ? a + b : input[i] == '-' ? a - b : a * b);
					}
				}
			}
		}
		return ans.empty() ? vector<int>{stoi(input)} : ans;
	}
};
