//
// Created by aleafall on 16-11-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn=505;
const int inf=0x3fffffff;

int cmax, n, sp, m;
int g[maxn][maxn], a[maxn] = {0}, d[maxn];
vector<int> pre[maxn], tempPath, path;
bool vis[maxn] = {0};
int minOut = inf, minIn = inf;
void Dijkstar(int st){
    fill(d, d + maxn, inf);
    d[st] = 0;
    for (int i = 0; i < n+1; ++i) {
        int u = -1, Min = inf;
        for (int j = 0; j < n+1; ++j) {
            if (d[j] < Min && vis[j] == 0) {
                u = j;
                Min = d[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0; j < n+1; ++j) {
            if (g[u][j] != inf) {
                if (d[j] > d[u] + g[u][j]) {
                    d[j] = d[u] + g[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                } else if (d[j] == d[u] + g[u][j]) {
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){
    tempPath.push_back(v);
    if (v == 0) {
        int tempNeed = 0, tempRamin = 0;
        for (int i = tempPath.size() - 1; i >= 0; --i) {
            if (a[tempPath[i]] > 0) {
                tempRamin += a[tempPath[i]];
            } else {
                if (tempRamin > abs(a[tempPath[i]])) {
                    tempRamin += a[tempPath[i]];
                } else {
                    tempNeed -= (tempRamin + a[tempPath[i]]);
                    tempRamin = 0;
                }
            }
        }
        if (tempNeed < minOut) {
            minOut = tempNeed;
            minIn = tempRamin;
            path = tempPath;
        } else if (tempNeed == minOut && tempRamin < minIn) {
            path = tempPath;
            minIn = tempRamin;
        }
        tempPath.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}
int main(){
    int v1, v2;
    cin >> cmax >> n >> sp >> m;
    fill(g[0], g[0] + maxn * maxn, inf);
    cmax /= 2;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        a[i] -= cmax;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        scanf("%d", &g[v1][v2]);
        g[v2][v1] = g[v1][v2];
    }
    Dijkstar(0);
    DFS(sp);
    cout << minOut << " ";
    for (int i = path.size()-1; i >=0; --i) {
        cout << path[i];
        if (i) {
            cout << "->";
        } else {
            cout<<" ";
        }
    }
    cout<<minIn<<endl;
    return 0;
}