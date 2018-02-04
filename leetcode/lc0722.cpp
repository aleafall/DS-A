//
// Created by aleafall on 17-11-19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> removeComments(vector<string>& source) {
		vector<string> ans;
		for (auto &&item :source) {
			for (int i = 0; i < (int) item.size() - 1; ) {
				if (item[i] == '/' && item[i + 1] == '/') {
					if (i == 0) {
						continue;
					} else {
						ans.push_back()
					}
				}
			}
		}
		for (int i = 0; i < source.size(); ) {
			for (int j = 0; j < (int) source[i].size() - 1; ++j) {
				if (source[i][j] == '/' && source[i][j+1] == '/') {
					if (j == 0) {
						continue;
					} else {
						ans.push_back(source[i].substr(0, i));
					}
					++i;
				} else if () {}
			}
		}
	}
};
