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
        if (preorder.empty()) {
            return 0;
        }
        vector<string> vs;
        string now;
        istringstream in(preorder);
        while (getline(in, now, ',')) {
            vs.push_back(now);
        }
        int cnt=0;
        for (size_t i = 0; i <vs.size()-1 ; ++i) {
            if (vs[i] == "#") {
                --cnt;
            } else
                ++cnt;
            if (cnt < 0) {
                return 0;
            }
        }
        return cnt == 0 && vs[vs.size() - 1] == "#";
    }
};
