//
// Created by aleafall on 17-4-29.
//

// very easy
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int ans = 0;
		for (int i = 0; i < timeSeries.size(); ++i) {
			if (i < (int) timeSeries .size()- 1) {
				if (timeSeries[i] + duration <= timeSeries[i + 1]) {
					ans += duration;
				} else {
					ans += timeSeries[i + 1] - timeSeries[i];
				}
			} else {
				ans += duration;
			}
		}
		return ans;
	}
};
