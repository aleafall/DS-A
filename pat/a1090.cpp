//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 100005;

vector<int> sup[maxn];
double p, r, ans = 0;
int max_level = -1, num = 0;

void DFS(int v,int level){
    if (sup[v].empty()) {
        if (level > max_level) {
            max_level = level;
            num = 1;
            ans = p * pow(1 + .01 * r, level);
        } else if (level == max_level) {
            ++num;
        }
        return;
    }
    for (int i = 0; i < sup[v].size(); ++i) {
        DFS(sup[v][i], level + 1);
    }
}
int main(){
    int n, index, root = 0;
    cin >> n >> p >> r;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &index);
        if (index != -1) {
            sup[index].push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2f %d\n", ans, num);
    return 0;
}
