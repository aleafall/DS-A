//
// Created by aleafall on 16-11-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=1005;
const int inf=0x3fffffff;

int n,m,k;
vector<int> g[maxn];
bool vis[maxn] = {0};

void DFS(int v,int q){
    vis[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != q && vis[g[v][i]] == 0) {
            DFS(g[v][i], q);
        }
    }
}
int main() {
    int v1, v2,q;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &q);
        fill(vis + 1, vis + n + 1, 0);
        int block=0;
        for (int j = 1; j <=n; ++j) {
            if (j != q && vis[j] == 0) {
                block++;
                DFS(j, q);
            }
        }
        cout<<block-1<<endl;
    }
    return 0;
}

