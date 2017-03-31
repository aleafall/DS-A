//
// Created by aleafall on 16-10-2.
//

#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxn = 10001;

struct Mem {
    double es, area;
    int num;

    Mem() : num(1), es(0), area(0) {}
} mem[maxn];

int father[maxn];

bool cmp(int a, int b) {
    double avg_area1 = mem[a].area / mem[a].num;
    double avg_area2 = mem[b].area / mem[b].num;
    if (avg_area1 != avg_area2) return avg_area1 > avg_area2;
    return a < b;
}

int findFather(int x) {
    if (x == father[x]) return x;
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
    map<int, vector<int>> mp;
    set<int> total;
    vector<int> final;
    for (int i = 0; i < maxn; ++i) {
        father[i] = i;
    }
    int n, k, id, fa, mo, kid;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &id, &fa, &mo, &k);
        total.insert(id);
        if (fa != -1) {
            total.insert(fa);
            Union(id, fa);
        }
        if (mo != -1) {
            total.insert(mo);
            Union(id, mo);
        }
        for (int j = 0; j < k; ++j) {
            scanf("%d", &kid);
            total.insert(kid);
            Union(kid, id);
        }
        scanf("%lf %lf", &mem[id].es, &mem[id].area);
    }
    for (set<int>::const_iterator it = total.cbegin(); it != total.cend(); ++it) {
        int F = findFather(*it);
        mp[F].push_back(*it);
    }
    for (auto it = mp.cbegin(); it != mp.cend(); it++) {
        sort(mp[it->first].begin(), mp[it->first].end());
        if (mp[it->first].size() > 1) {
            for (int i = 0; i < mp[it->first].size(); ++i) {
                if (i) {
                    mem[mp[it->first][0]].es += mem[mp[it->first][i]].es;
                    mem[mp[it->first][0]].area += mem[mp[it->first][i]].area;
                    mem[mp[it->first][0]].num++;
                }
            }
        }
        final.push_back(mp[it->first][0]);
    }
    sort(final.begin(), final.end(), cmp);
    cout << final.size() << endl;
    for (int i = 0; i < final.size(); ++i) {
        int cnt = mem[final[i]].num;
        printf("%04d %d %.3f %.3f\n", final[i], cnt, mem[final[i]].es / cnt,
               mem[final[i]].area / cnt);
    }
    return 0;
}

