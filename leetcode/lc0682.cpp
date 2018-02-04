//
// Created by aleafall on 17-9-24.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> vi;
		for (auto &&item :ops) {
			 if (item == "+") {
				int last1 = 0, last2 = 0;
				if (!vi.empty()) {
					last1 = vi.back();
				}
				if (vi.size() > 1) {
					last2 = vi[vi.size() - 2];
				}
				vi.push_back(last1 + last2);
			} else if (item == "D") {
				int last = 0;
				if (!vi.empty()) {
					last = vi.back() * 2;
				}
				vi.push_back(last);
			} else if (item[0]=='C'){
				vi.pop_back();
			} else {
				vi.push_back(stoi(item));
			}
		}
		int sum = 0;
		for (auto &&item :vi) {
			sum += item;
		}
		return sum;
	}
};
