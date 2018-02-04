//
// Created by t-xiuyan on 7/29/2017.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
	    string ans;
        unordered_set<string> st;
	    for (auto &&item :dict) {
		    st.insert(item);
	    }
	    string now;
	    for (int i = 0; i < sentence.size(); ++i) {
		    if (sentence[i] != ' ') {
			    now += sentence[i];
			    if (st.count(now)) {
				    ans += ans.empty() ? now : " " + now;
				    while (i < sentence.size() && sentence[i] != ' ') {
					    i++;
				    }
				    now.clear();
			    }
		    } else {
			    ans += ans.empty() ? now : " " + now;
			    now.clear();
		    }
		    if (i == sentence.size() - 1 && !now.empty()) {
			    ans += ans.empty() ? now : " " + now;
		    }
	    }
	    return ans;
    }
};
int main() {

    return 0;
}
