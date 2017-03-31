//
// Created by aleafall on 17-2-26.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.empty()) {
			return 1;
		}
		stack<int> st;
		int index = 0;
		for (auto &&item  :pushV) {
			st.push(item);
			while (!st.empty()&&st.top()==popV[index]){
				st.pop();
				++index;
			}
		}
		return st.empty();
	}
};

int main(){
	vector<int> pushV{1,2,3,4,5},popV{4,3,5,1,2};
	Solution solution;
	cout << solution.IsPopOrder(pushV, popV) << endl;
}