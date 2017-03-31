//
// Created by aleafall on 16-10-3.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
const int maxn = 1001;
int father[maxn];
vector<int> hobby[maxn];

int findFather(int x) {
    if (father[x] == x) return x;
    else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faB] = faA;
}

int main() {
    int n, k, h;
    map<int, int> mp;
    for (int i = 0; i < maxn; i++)
        father[i] = i;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d: ", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            hobby[h].push_back(i);
        }
    }
    for (int i = 1; i < maxn; i++) {
        if (hobby[i].size() > 1) {
            for (int j = 1; j < hobby[i].size(); j++)
                Union(hobby[i][0], hobby[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        int F = findFather(i);
        if (mp.find(F) != mp.end()) mp[F]++;
        else mp[F] = 1;
    }
    int cnt = 0, ans[maxn];
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        ans[cnt++] = it->second;
    }
    cout << cnt << endl;
    sort(ans, ans + cnt);
    for (int i = 0; i < cnt; i++) {
        cout << ans[cnt - i - 1];
        if (i < cnt - 1) cout << ' ';
        else cout << endl;
    }
    return 0;
}
