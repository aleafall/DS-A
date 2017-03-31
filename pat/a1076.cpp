//
// Created by aleafall on 16-11-30.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1005;

int n,L, ans = 0;
vector<int> user[maxn];

void DFS(int v, int level) {
    if (level > L) {
        return;
    }
    ++ans;
    for (int i = 0; i < user[v].size(); ++i) {
        DFS(user[v][i], level + 1);
    }
}


int main(){
    cin >> n >> L;
    int k,m, uid;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &uid);
            user[uid].push_back(i + 1);
        }
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &uid);
        for (int j = 0; j < user[uid].size(); ++j) {
            DFS(user[uid][j], 1);
        }
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}
