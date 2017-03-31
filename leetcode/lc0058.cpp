//
// Created by aleafall on 16-11-17.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream in(s);
        string ans;
        while (in>>ans) {
            ;
        }
        return (int) ans.size();
    }
};
