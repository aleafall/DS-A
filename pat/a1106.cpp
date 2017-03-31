//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 100005;

double p, r;
int n,num=0, Min = 0x3fffffff;
vector<int> sup[maxn];

void DFS(int v,int level){
    if (sup[v].empty()) {
        if (level < Min) {
            Min = level;
            num = 1;
        } else if (level == Min) {
            num++;
        }
        return;
    }
    for (int i = 0; i < sup[v].size(); ++i) {
        DFS(sup[v][i], level + 1);
    }
}
int main() {
    int k, kid;
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &kid);
            sup[i].push_back(kid);
        }
    }
    DFS(0, 0);
    printf("%.4f %d\n", p * pow(1 + .01 * r, Min), num);
    return 0;
}
