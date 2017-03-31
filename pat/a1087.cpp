//
// Created by aleafall on 16-12-2.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 201;
const int inf = 0x3fffffff;

int n, ans = 0, max_hp = 0;
double avg_hp = 0;
int g[maxn][maxn], weight[maxn], d[maxn];
bool vis[maxn];
vector<int> pre[maxn], tempPath, path;

void Dijkstra(int s) {
    fill(d, d + maxn, inf);
    d[s] = 0;
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

void DFS(int v) {
    if (v == 0) {
        tempPath.push_back(v);
        ++ans;
        int sum = 0;
        double avg = 0;
        for (int i = 0; i < tempPath.size(); ++i) {
            sum += weight[tempPath[i]];
        }
        avg = 1.0 * sum / (tempPath.size() - 1);
        if (sum > max_hp) {
            path = tempPath;
            max_hp = sum;
            avg_hp = avg;
        } else if (sum == max_hp && avg > avg_hp) {
            path = tempPath;
            avg_hp = avg;
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

int main() {
    int k, rom;
    fill(g[0], g[0] + maxn * maxn, inf);
    string head, s1, s2;
    int v1, v2;
    map<string, int> str2int;
    map<int, string> int2str;
    cin >> n >> k >> head;
    str2int[head] = 0;
    int2str[0] = head;
    for (int i = 1; i < n; ++i) {
        cin >> s1 >> weight[i];
        int2str[i] = s1;
        str2int[s1] = i;
        if (s1 == "ROM") {
            rom = i;
        }
    }
    for (int i = 0; i < k; ++i) {
        cin >> s1 >> s2;
        v1 = str2int[s1], v2 = str2int[s2];
        cin >> g[v1][v2];
        g[v2][v1] = g[v1][v2];
    }
    Dijkstra(0);
    DFS(rom);
    printf("%d %d %d %d\n", ans, d[rom], max_hp, (int) avg_hp);
    for (int i = path.size() - 1; i >= 0; --i) {
        if (i) {
            cout << int2str[path[i]] << "->";
        } else {
            cout << int2str[path[i]] << endl;
        }
    }
    return 0;
}
