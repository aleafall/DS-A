//
// Created by aleafall on 16-10-18.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num-9*((num-1)/9);
    }
};
