//
// Created by aleafall on 17-5-23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int ans = 0;
		sort(citations.begin(), citations.end());
		for (int i = (int) citations.size() - 1; i >= 0; --i) {
			if (citations[i]>= citations.size() - i ) {
				ans = max(ans, (int)citations.size() - i);
			}
		}
		return ans;
	}
};

int main(){
	unsigned int x = 0;
	auto y = x - 1;
	cout << (1ll << 32) - 1 << endl;
	cout << y << endl;
}