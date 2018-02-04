//
// Created by aleafall on 17-9-29.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void DFS(int tempSum, int now, int hashTable[], int &sum) {
	tempSum+= hashTable[now];
	int level = now / 10, index = now % 10;
	bool ended = 1;
	int left = (level + 1) * 10 + index * 2 - 1;
	int right = left + 1;
	if (hashTable[left]) {
		ended = 0;
		DFS(tempSum, left, hashTable, sum);
	}
	if (hashTable[right]) {
		ended = 0;
		DFS(tempSum,right, hashTable, sum);
	}
	if (ended) {
		sum += tempSum;
	}
}
int pathSum(vector<int> &nums) {
	if (nums.empty()) {
		return 0;
	}
	int sum = 0;
	int hashTable[101] = {0};
	for (auto &&item :nums) {
		hashTable[item / 10] = item % 10;
	}
	DFS(0,nums.front() / 10, hashTable, sum);
	return sum;
}


int main() {
	vector<int> vi{113, 215, 221};
	cout << pathSum(vi) << endl;
    return 0;
}
