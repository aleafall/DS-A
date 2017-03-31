//
// Created by aleafall on 16-12-10.
//

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
bool vis[maxn] = {0};

int main() {
    int n, x1, x2, m;
    int a[maxn];
    map<int, int> mp;
    vector<int> ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x1, &x2);
        mp[x1] = x2;
        mp[x2] = x1;
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
        vis[a[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {
        if (!(vis[a[i]] && vis[mp[a[i]]])) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (i < ans.size() - 1) {
            printf("%05d ", ans[i]);
        } else {
            printf("%05d\n", ans[i]);
        }
    }
    return 0;
}