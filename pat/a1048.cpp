//
// Created by aleafall on 16-11-26.
//

#include <iostream>

using namespace std;

const int maxn = 501;

int main() {
    int n, m, a;
    int vis[maxn] = {0};
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++vis[a];
    }
    for (int i = 1; i < maxn; ++i) {
        if (vis[i] && m - i > 0 && m - i < maxn) {
            --vis[i];
            if (vis[m - i]) {
                printf("%d %d\n", i, m - i);
                return 0;
            } else {
                ++vis[i];
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
