//
// Created by aleafall on 18-1-31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		const int MAXN = 0x3fffffff;
		vector<pair<int, int>> vi(arr.size());
		int Min = MAXN, Max = -1;
		for (int i = 0; i < arr.size(); ++i) {
			vi[i].first = Max;
			Max = max(arr[i], Max);
		}
		for (int i = (int) arr.size() - 1; i >= 0; --i) {
			vi[i].second = Min;
			Min = min(Min, arr[i]);
		}
		int ans = 0;
		int index = 0;
		while (index < arr.size()) {
			Max = -1, Min = MAXN;
			for (int i = index; i < arr.size(); ++i) {
				Max = max(Max, arr[i]);
				Min = min(Min, arr[i]);
				if (Min > vi[index].first && Max < vi[i].second) {
					index = i + 1;
					ans++;
					break;
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution solution;
	vector<int> vi{2, 1, 3, 4, 4};
	cout<<solution.maxChunksToSorted(vi)<<endl;
	return 0;
}
