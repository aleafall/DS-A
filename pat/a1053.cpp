//
// Created by aleafall on 16-11-26.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 101;

int n, m, s;
vector<int> tree[maxn];
int weight[maxn];

bool cmp(int a, int b){
    return weight[a] > weight[b];
}
void DFS(int v, vector<int> &vi,int temp){
    temp += weight[v];
    vi.push_back(v);
    if (tree[v].empty()) {
        if (temp==s){
            for (int i = 0; i < vi.size(); ++i) {
                if (i < vi.size() - 1) {
                    cout << weight[vi[i]] << " ";
                } else {
                    cout << weight[vi[i]] << endl;
                }
            }
        }
        vi.pop_back();
        return;
    }
    if (temp >= s) {
        vi.pop_back();
        return;
    }
    for (int i = 0; i < tree[v].size(); ++i) {
        DFS(tree[v][i], vi, temp);
    }
    vi.pop_back();
}
int main(){
    int id, k, kid;
    cin >> n >> m >> s;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            cin >> kid;
            tree[id].push_back(kid);
        }
        sort(tree[id].begin(), tree[id].end(),cmp);
    }
    vector<int> vi;
    DFS(0, vi, 0);
    return 0;
}
