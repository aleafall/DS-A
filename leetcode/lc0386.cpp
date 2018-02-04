//
// Created by aleafall on 17-9-27.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> ans(n);
		for (int i = 0; i < n; ++i) {
			ans[i] = i + 1;
		}
		sort(ans.begin(), ans.end(),[](int a,int b){
			return to_string(a) < to_string(b);
		});
		return ans;
	}
};
