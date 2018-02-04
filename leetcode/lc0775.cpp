//
// Created by aleafall on 18-1-29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int global, local = 0;
public:
	bool isIdealPermutation(vector<int> &A) {
		global = 0;
		local = 0;
		vector<int> temp(A.size(), 0);
		for (int i = 0; i < (int) A.size() - 1; ++i) {
			if (A[i] > A[i + 1]) {
				local++;
			}
		}
		mergeSort(A, 0, (int) A.size() - 1, temp);
		return global == local;
	}

	void merge(vector<int> &vi, int first, int mid, int last, vector<int> &temp) {
		int i = first, j = mid, m = mid + 1, n = last, k = 0;
		while (i <= j && m <= n) {
			if (vi[i] < vi[m]) {
				temp[k++] = vi[i++];
			} else {
				temp[k++] = vi[m++];
				global += j - i + 1;
			}
		}
		while (i <= j) {
			temp[k++] = vi[i++];
		}
		while (m <= n) {
			temp[k++] = vi[m++];
		}
		for (int index = 0; index < k; ++index) {
			vi[first + index] = temp[index];
		}
	}

	void mergeSort(vector<int> &vi, int first, int last, vector<int> &temp) {
		if (first < last) {
			int mid = (first + last) / 2;
			mergeSort(vi, first, mid, temp);
			mergeSort(vi, mid + 1, last, temp);
			merge(vi, first, mid, last, temp);
		}
	}
};

int main() {
	vector<int> vi{1, 0, 2};
	Solution s;
	cout << s.isIdealPermutation(vi) << endl;
}
