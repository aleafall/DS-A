//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 501;
const int inf = 0x3fffffff;
int n, m, S, D;
int g[maxn][maxn], c[maxn][maxn], d[maxn], cost[maxn];
bool vis[maxn] = {0};
vector<int> pre[maxn], path;

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    fill(cost, cost + maxn, inf);
    d[s] = 0, cost[s] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, Min = inf;
        for (int j = 0; j < n; ++j) {
            if (d[j] < Min && vis[j] == 0) {
                u = j;
                Min = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0; j < n; ++j) {
            if (g[u][j] != inf) {
                if (d[j] > d[u] + g[u][j]) {
                    d[j] = d[u] + g[u][j];
                    cost[j] = cost[u] + c[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                } else if (d[j] == d[u] + g[u][j] && cost[j] > cost[u] + c[u][j]) {
                    cost[j] = cost[u] + c[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> S >> D;
    fill(g[0], g[0] + maxn * maxn, inf);
    fill(c[0], c[0] + maxn * maxn, inf);
    int v1, v2;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        scanf("%d %d", &g[v1][v2], &c[v1][v2]);
        g[v2][v1] = g[v1][v2];
        c[v2][v1] = c[v1][v2];
    }
    Dijkstra(S);
    int index = D;
    while (!pre[index].empty()) {
        path.push_back(index);
        index = pre[index][0];
    }
    path.push_back(S);
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << d[D] << " " << cost[D] << endl;
    return 0;
}



