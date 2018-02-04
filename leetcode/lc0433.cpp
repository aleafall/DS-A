//
// Created by aleafall on 17-9-17.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
	int ans = 0x3fffffff;
	string str = "ACGT";
public:
	int minMutation(string start, string end, vector<string> &bank) {
		unordered_set<string> st;
		for (auto &&item :bank) {
			st.insert(item);
		}
		DFS(0, start, end, st);
		return ans == 0x3fffffff ? -1 : ans;
	}

	void DFS(int cnt, string &now, string &end, unordered_set<string> &st) {
		if (now == end) {
			ans = min(ans, cnt);
			return;
		}
		for (int i = 0; i < now.size(); ++i) {
			char temp = now[i];
			for (int j = 0; j < str.size(); ++j) {
				if (str[j] != temp) {
					now[i] = str[j];
					if (st.count(now)) {
						st.erase(now);
						DFS(cnt + 1, now, end, st);
						st.insert(now);
					}
				}
			}
			now[i] = temp;
		}
	}
};

int main() {
	Solution solution;
	string start = "AACCGGTT";
	string end = "AAACGGTA";
	vector<string> vs{"AACCGGTA", "AACCGCTA", "AAACGGTA"};
	cout << solution.minMutation(start, end, vs) << endl;
	return 0;
}
