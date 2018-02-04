//
// Created by aleafall on 17-9-17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int cnt = 0, pos = -1;
		for (int i = 0; i < word.size(); ++i) {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				++cnt;
				pos = i;
			}
		}
		if ((word.size() > 1 && cnt == word.size()) || (pos == 0 && cnt == 1 ) || cnt == 0) {
			return 1;
		}
		return 0;
	}
};
