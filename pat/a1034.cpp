//
// Created by aleafall on 16-11-24.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 2005;
const int inf = 0x3fffffff;

int g[maxn][maxn] = {0};
bool vis[maxn] = {0};
int n, k, index = 0, holds[maxn] = {0};

void DFS(int v, int &sum, vector<int> &vi) {
    vis[v] = 1;
    vi.push_back(v);
    for (int i = 0; i < index; ++i) {
        if (g[v][i]) {
            sum += g[v][i];
            holds[v] += g[v][i];
            holds[i] += g[v][i];
            if (vis[i] == 0) {
                DFS(i, sum, vi);
            }
        }
    }
}

int main() {
    string name1, name2;
    int time, v1, v2;
    map<string, int> str2int, ans;
    map<int, string> int2str;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> name1 >> name2 >> time;
        if (str2int.find(name1) != str2int.end()) {
            v1 = str2int[name1];
        } else {
            str2int[name1] = index;
            v1 = index;
            int2str[v1] = name1;
            ++index;
        }
        if (str2int.find(name2) != str2int.end()) {
            v2 = str2int[name2];
        } else {
            str2int[name2] = index;
            v2 = index;
            int2str[v2] = name2;
            ++index;
        }
        g[v1][v2] += time, g[v2][v1] += time;
    }
    int cnt = 0;
    for (int i = 0; i < index; ++i) {
        if (vis[i] == 0) {
            vector<int> vi;
            int sum = 0;
            DFS(i, sum, vi);
            sum /= 2;
            if (sum > k && vi.size() > 2) {
                ++cnt;
                int u = -1, Max = -1;
                for (auto item:vi) {
                    if (holds[item] > Max) {
                        Max = holds[item];
                        u = item;
                    }
                }
                ans[int2str[u]] = (int) vi.size();
            }
        }
    }
    cout << cnt << endl;
    for (auto item:ans) {
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}
