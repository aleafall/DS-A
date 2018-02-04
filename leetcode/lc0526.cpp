//
// Created by aleafall on 17-5-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	int ans;
public:
	int countArrangement(int N) {
		ans = 0;
		vector<int> hashTable(N, 0);
		DFS(hashTable, 1);
		return ans;
	}
	void DFS(vector<int> &hashTable,int index){
		if (index> hashTable.size()) {
			++ans;
			return;
		}
		for (int i = 0; i < hashTable.size(); ++i) {
			if (!hashTable[i] && ((i + 1) % index == 0 || index % (i + 1) == 0)) {
				hashTable[i] = 1;
				DFS(hashTable, index + 1);
				hashTable[i] = 0;
			}
		}
	}
};
