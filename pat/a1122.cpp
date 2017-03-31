//
// Created by aleafall on 16-12-10.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;

int g[maxn][maxn] = {0};
int vis[maxn] = {0};

int n, m, a[maxn];

bool check(int cnt) {
    for (int i = 0; i < cnt; ++i) {
        if (i < cnt - 1) {
            if (g[a[i]][a[i + 1]] == 0) {
                return 0;
            }
        }
        ++vis[a[i]];
    }
    for (int i = 0; i < cnt; ++i) {
        if (i == 0 || i == cnt - 1) {
            if (vis[a[i]] != 2) {
                return 0;
            }
        } else {
            if (vis[a[i]] != 1) {
                return 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int k, v1, v2, cnt;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = 1;
        g[v2][v1] = 1;
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            scanf("%d", &a[j]);
        }
        check(cnt) ? printf("YES\n") : printf("NO\n");
        fill(vis, vis + maxn, 0);
    }
    return 0;
}
