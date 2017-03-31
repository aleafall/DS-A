//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int mod = 1000000007;
	int InversePairs(vector<int> data) {
		if (data.empty()) {
			return 0;
		}
		vector<int> order = data;
		long long ans = merge(data, order, 0, (int) data.size() - 1) % mod;
		return (int) ans;
	}

	long long merge(vector<int> &data,vector<int> &order,int left,int right){
		if (left >= right) {
//			order[left] = data[left];
			return 0;
		}
		int mid = (right + left) / 2;
		long long numOfLeft = merge(data, order, left, mid);
		long long numOfRight = merge(data, order, mid + 1, right);
		numOfLeft %= mod;
		numOfRight %= mod;
		int i = mid, j = right, index = right, cnt = 0;
		while (i >= left && j >= mid + 1) {
			if (data[i] > data[j]) {
				order[index--] = data[i--];
				cnt += j - mid;
				if (cnt > mod) {
					cnt %= mod;
				}
			} else {
				order[index--] = data[j--];
			}
		}
		while (i >= left) {
			order[index--] = data[i--];
		}
		while (j >= mid + 1) {
			order[index--] = data[j--];
		}
		for (int k = left; k <= right; ++k) {
			data[k] = order[k];
		}
		return numOfLeft + numOfRight + cnt;
	}
};

int main() {
	Solution solution;
	vector<int> data{1, 2, 3, 4, 5, 6, 7, 0};
	cout << solution.InversePairs(data) << endl;
}
