//
// Created by aleafall on 16-11-14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.size() <= 1) {
            return (int) ratings.size();
        }
        int ans = 0;
        vector<int> cnt(ratings.size(), 1);
        for (size_t i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                cnt[i] = cnt[i - 1] + 1;
            }
        }
        for (size_t i = ratings.size()-2; i >=0 ; --i) {
            if (ratings[i] > ratings[i + 1] && cnt[i] <= cnt[i + 1]) {
                cnt[i] = cnt[i + 1] + 1;
            }
        }
        for (auto item:cnt) {
            ans += item;
        }
        return ans;
    }
};


