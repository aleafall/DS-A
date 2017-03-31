//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 2501;

struct Course {
    vector<string> name;
} course[maxn];

int main() {
    map<int, vector<int>> mp;
    int n, m, k, id;
    cin >> n >> m;
    char str[5];
    string name;
    for (int i = 0; i < n; ++i) {
        getchar();
        scanf("%s %d", str, &k);
        name = string(str);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &id);
            course[id].name.push_back(name);
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf("%d %d\n", i, (int) course[i].name.size());
        sort(course[i].name.begin(), course[i].name.end());
        for (int j = 0; j < course[i].name.size(); ++j) {
            printf("%s\n", course[i].name[j].c_str());
        }
    }
    return 0;
}
