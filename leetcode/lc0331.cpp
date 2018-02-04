//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> vs;
        string now;
        istringstream in(preorder);
        while (getline(in, now, ',')) {
            vs.push_back(now);
        }
	    int cnt = 1;
	    for (auto &&item :vs) {
		    if (--cnt < 0) {
			    return 0;
		    }
		    if (item != "#") {
			    cnt += 2;
		    }
	    }
	    return cnt == 0;
    }
};
