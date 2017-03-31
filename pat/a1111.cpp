//
// Created by aleafall on 16-12-4.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 501;
const int inf = 0x3fffffff;

int dis[maxn][maxn], t[maxn][maxn], d[maxn], f[maxn];
vector<int> pre[maxn], tempPath, path1, path2;
bool vis[maxn] = {0};
int n;
int beg,e;

void Dijstra1(int st){
    fill(d, d + maxn, inf);
    d[st] = 0;
    f[st] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, Min = inf;
        for (int j = 0; j < n; ++j) {
            if (d[j] < Min && vis[j] == 0) {
                Min = d[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0; j < n; ++j) {
            if (dis[u][j]!=inf) {
                if (d[j] > d[u] + dis[u][j]||(d[j]==d[u]+dis[u][j]&&f[j]>f[u]+t[u][j])) {
                    d[j] = d[u] + dis[u][j];
                    f[j] = f[u] + t[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
            }
        }
    }
}
void Dijstra2(int st){
    for (int i = 0; i < n; ++i) {
        pre[i].clear();
    }
    fill(f, f + maxn, inf);
    fill(vis, vis + maxn, 0);
    f[st] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1, Min = inf;
        for (int j = 0; j < n;  ++j) {
            if (f[j] < Min && vis[j] == 0) {
                Min = f[j];
                u = j;
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0; j < n; ++j) {
            if (t[u][j] != inf) {
                if (f[j] > f[u] + t[u][j]) {
                    pre[j].clear();
                    pre[j].push_back(u);
                    f[j] = f[u] + t[u][j];
                } else if (f[j] == f[u] + t[u][j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}
void DFS(int v){
    if (v == beg) {
        tempPath.push_back(v);
        if (path2.empty()||path2.size()>tempPath.size()) {
            path2 = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
void print(vector<int> &vi){
    for (int i = vi.size()-1; i >=0 ; --i) {
        if (i) {
            printf("%d -> ", vi[i]);
        } else {
            printf("%d\n", vi[i]);
        }
    }
}
int main(){
    int m,v1,v2,tag,len,time;
    fill(dis[0], dis[0] + maxn * maxn, inf);
    fill(t[0], t[0] + maxn * maxn, inf);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d %d", &v1, &v2, &tag, &len, &time);
        dis[v1][v2] = len;
        t[v1][v2] = time;
        if (tag == 0) {
            dis[v2][v1] = len;
            t[v2][v1] = time;
        }
    }
    scanf("%d %d", &beg, &e);
    Dijstra1(beg);
    int v = e;
    while (v != beg) {
        path1.push_back(v);
        v = pre[v][0];
    }
    path1.push_back(beg);
    Dijstra2(beg);
    DFS(e);
    if (path1 == path2) {
        printf("Distance = %d; Time = %d: ", d[e], f[e]);
        print(path1);
    } else {
        printf("Distance = %d: ", d[e]);
        print(path1);
        printf("Time = %d: ", f[e]);
        print(path2);
    }
    return 0;
}
