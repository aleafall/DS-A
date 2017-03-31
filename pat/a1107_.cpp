//
// Created by aleafall on 16-12-3.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1005;

int n, father[maxn];
vector<int> hobbys[maxn];

int findFather(int x){
    if (father[x] == x) {
        return x;
    } else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}
void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faB] = faA;
    }
}
int main(){
    int k,hb,total = 0;
    cin>>n;
    for (int i = 0; i < maxn; ++i) {
        father[i] = i;
    }
    for (int i = 0; i <n ; ++i) {
        scanf("%d: ", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &hb);
            hobbys[hb].push_back(i + 1);
            total = max(total, hb);
        }
    }
    for (int i = 1; i <=total ; ++i) {
        for (int j = 1; j < hobbys[i].size(); ++j) {
            Union(hobbys[i][0], hobbys[i][j]);
        }
    }
    map<int,int> mp;
    for (int i = 1; i <=n ; ++i) {
        int f = findFather(i);
        if (mp.find(f) != mp.end()) {
            mp[f]++;
        } else {
            mp[f] = 1;
        }
    }
    vector<int> ans;
    for (map<int,int>::iterator it = mp.begin(); it!=mp.end() ; ++it) {
        ans.push_back(it->second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = ans.size()-1; i >=0 ; --i) {
        if (i) {
            printf("%d ", ans[i]);
        } else {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
