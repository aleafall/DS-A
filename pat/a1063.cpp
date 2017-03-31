//
// Created by aleafall on 16-11-28.
//

#include <iostream>
#include <set>

using namespace std;

const int maxn = 51;
const int maxm = 10001;

int main() {
    int n, len[maxn], v, k;
    set<int> num[maxn];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &len[i]);
        for (int j = 1; j <= len[i]; ++j) {
            scanf("%d", &v);
            num[i].insert(v);
        }
    }
    int v1, v2;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &v1, &v2);
        int size = 0;
        for (auto item:num[v1]) {
            if (num[v2].find(item) != num[v2].end()) {
                ++size;
            }
        }
        printf("%.1f%%\n", 100.0 * (size) /(num[v1].size()+num[v2].size()- size));
    }
    return 0;
}
