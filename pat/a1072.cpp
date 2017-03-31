//
// Created by aleafall on 16-11-29.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1020;
const int inf = 0x3fffffff;

int n, m, k, ds;
int g[maxn][maxn], d[maxn];
bool vis[maxn];
vector<int> pre[maxn], tempPath, path;


int main(){
    fill(g[0], g[0] + maxn * maxn, inf);
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    int p1,p2,dist;
    char str1[5], str2[5];
    for (int i = 0; i < k; ++i) {
        getchar();
        scanf("%s %s %d", str1, str2, &dist);
        if (str1[0] != 'G') {
            p1 = atoi(str1);
        } else {
            int len = (int) strlen(str1);
            p1 = 0;
            for (int j = 1; j < len; ++j) {
                p1 = p1 * 10 + str1[j] - '0';
            }
            p1 += n;
        }
        if (str2[0] != 'G') {
            p2 = atoi(str2);
        } else {
            int len = (int) strlen(str2);
            p2 = 0;
            for (int j = 1; j < len; ++j) {
                p2 = p2 * 10 + str2[j] - '0';
            }
            p2+=n;
        }
        --p1, --p2;
        g[p1][p2] = g[p2][p1] = dist;
    }
    for (int i = n; i < m+n; ++i) {

    }
}
