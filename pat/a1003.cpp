//
// Created by aleafall on 16-11-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=501;
const int inf=0x3fffffff;

int n, m, c1, c2;
int road_cnt=0,man_cnt=0;
int g[maxn][maxn], s[maxn], r[maxn];
bool vis[maxn] = {0};
vector<int> pre[maxn];

void Dijkstra(int st){
    fill(s, s + n, inf);
    s[st] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, Min = inf;
        for (int j = 0; j < n; ++j) {
            if (s[j] != inf && vis[j] == 0) {
                if (s[j] < Min) {
                    Min = s[j];
                    u = j;
                }
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0; j < n; ++j) {
            if (g[u][j] != inf) {
                if (s[j] > s[u] + g[u][j]) {
                    s[j] = s[u] + g[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                } else if (s[j] == s[u] + g[u][j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void DFS(int v, int cnt) {
    cnt += r[v];
    if (v == c1) {
        road_cnt++;
        man_cnt = max(man_cnt, cnt);
        return;
    }
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i], cnt);
    }
}
int main() {
    int r1, r2;
    fill(g[0], g[0] + maxn * maxn, inf);
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &r1, &r2);
        scanf("%d", &g[r1][r2]);
        g[r2][r1] = g[r1][r2];
    }
    Dijkstra(c1);
    DFS(c2, 0);
    cout<<road_cnt<<" "<<man_cnt<<endl;
    return 0;
}
