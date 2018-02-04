//
// Created by aleafall on 17-9-26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int leastInterval(vector<char> &tasks, int n) {
		int cnt[26] = {0};
		int Max = 0;
		for (auto &&item :tasks) {
			cnt[item - 'A']++;
			Max = max(Max, cnt[item - 'A']);
		}
		int ans = (Max - 1) * (n + 1);
		for (int item : cnt) {
			if (item == Max) {
				ans++;
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<char> v{'A', 'A', 'A', 'B', 'B', 'B','D','D','D','C','A','A','E','E'};
	int n = 2;
	cout << solution.leastInterval(v, n) << endl;
    return 0;
}
