//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 105;

vector<int> fam[maxn];
int a[maxn] = {0};

void DFS(int v,int level){
    a[level]++;
    for (int i = 0; i < fam[v].size(); ++i) {
        DFS(fam[v][i], level + 1);
    }
}
int main(){
    int n, m, id, k, kid;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            cin >> kid;
            fam[id].push_back(kid);
        }
    }
    DFS(1, 1);
    int ans = 0, max_level = 0;
    for (int i = 0; i < maxn; ++i) {
        if (a[i] > ans) {
            ans = a[i];
            max_level = i;
        }
    }
    cout << ans << " " << max_level << endl;
    return 0;
}