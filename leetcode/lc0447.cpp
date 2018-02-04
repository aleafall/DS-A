//
// Created by aleafall on 17-9-21.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int sum = 0;
		for (int i = 0; i < points.size(); ++i) {
			unordered_map<int, int> dis;
			for (int j = 0; j < points.size(); ++j) {
				if (j == i) {
					continue;
				}
				int now = (points[i].first - points[j].first) * (points[i].first - points[j].first) +
				          (points[i].second - points[j].second) * (points[i].second - points[j].second);
				dis[now]++;
			}
			for (auto &&item :dis) {
				sum += item.second * (item.second - 1);
			}
		}
		return sum;
	}
};

int main() {
	Solution solution;
	vector<pair<int, int> > vi{{0, 0},
	                           {1, 0},
	                           {2, 0}};
	cout << solution.numberOfBoomerangs(vi) << endl;
    return 0;
}
