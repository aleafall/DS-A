//
// Created by aleafall on 16-10-24.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int sqr=num/2;
        int cnt=100;
        for (size_t i = 0; i < cnt; ++i) {
            sqr= (int) ((sqr + 1.0 * num / sqr) / 2);
        }
        return sqr*sqr==num;
    }
};
