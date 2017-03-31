//
// Created by aleafall on 17-2-16.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> ans;
		if (input.size() < k) {
			return ans;
		}
		/*int a[k + 1];
		for (int i = 0; i < input.size() && i < k; ++i) {
			a[i + 1] = input[i];
		}
		buildHeap(a, k);
		for (int i = k; i < input.size(); ++i) {
			if (input[i] < a[1]) {
				a[1] = input[i];
				adjust(a, 1, k);
			}
		}
		for (int i = 1; i <= k; ++i) {
			ans.push_back(a[i]);
		}
		sort(ans.begin(), ans.end());
		return ans;*/
		quickSelect(input, 0, input.size() - 1, k - 1);
		return vector<int>(input.begin(), input.begin() + k);
	}

	int quickSelect(vector<int> &vi,int left,int right,int k){
		int i = left, j = right, mid = vi[(left + right) >> 1];
		while (i <= j) {
			while (vi[i] < mid) {
				++i;
			}
			while (vi[j] > mid) {
				--j;
			}
			if (i <= j) {
				swap(vi[i], vi[j]);
				++i, --j;
			}
		}
		if (j > left && k <= j) {
			return quickSelect(vi, left, j, k);
		}
		if (i < right && k >= i) {
			return quickSelect(vi, i, right, k);
		}
		return vi[k];
	}
	void buildHeap(int a[], int n) {
		for (int i = n / 2; i > 0; --i) {
			adjust(a, i, n);
		}
	}

	void adjust(int a[], int i, int n) {
		a[0]= a[i];
		for (int j = 2 * i; j <= n; j *= 2) {
			if (j < n && a[j + 1] > a[j]) {
				++j;
			}
			if (a[j] >= a[0]) {
				a[i] = a[j];
				i = j;
			} else {
				break;
			}
		}
		a[i] = a[0];
	}
};

int main(){
	Solution solution;
	vector<int> vi{4, 5, 1, 6, 2, 7, 3, 8};
	int k = 4;
	vector<int> ans = solution.GetLeastNumbers_Solution(vi, k);
	for (auto item:ans) {
		cout << item << endl;
	}
}
