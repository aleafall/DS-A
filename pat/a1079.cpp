//
// Created by aleafall on 16-12-1.
//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 100005;

vector<int> sup[maxn];
double amount[maxn] = {0};

double p, r, ans = 0;

void DFS(int v, int level){
    if (sup[v].empty()) {
        ans += amount[v] * p * pow(1 + 0.01 * r, level);
        return;
    }
    for (int i = 0; i < sup[v].size(); ++i) {
        DFS(sup[v][i], level + 1);
    }
}
int main(){
    int n, k, id;
    double x;
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &id);
            sup[i].push_back(id);
        }
        if (k == 0) {
            scanf("%lf", &x);
            amount[i] = x;
        }
    }
    DFS(0, 0);
    printf("%.1f\n", ans);
    return 0;
}