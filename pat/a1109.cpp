//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 10005;

struct Group {
    string name;
    int height;
} group[maxn];

bool cmp(Group a, Group b) {
    if (a.height != b.height) {
        return a.height > b.height;
    }
    return a.name < b.name;
}

int main(){
    int n, k;
    char str[10];
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s %d", str, &group[i].height);
        group[i].name = string(str);
    }
    sort(group, group + n, cmp);
    int mod = n % k, index = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> left, right;
        int beg = index+1,end;
        if (i == 0&&mod) {
            end =index+ n / k + mod;
        } else {
            end =index+ n / k;
        }
        left.push_back(index);
        for (int j = beg; j < end; ++j) {
            if ((j - beg) & 1) {
                right.push_back(j);
            } else {
                left.push_back(j);
            }
        }
        reverse(left.begin(), left.end());
        left.insert(left.end(), right.begin(), right.end());
        for (int j = 0; j < left.size(); ++j) {
            if (j < left.size() - 1) {
                printf("%s ", group[left[j]].name.c_str());
            } else {
                printf("%s\n", group[left[j]].name.c_str());

            }
        }
        index = end;
    }
    return 0;
}
