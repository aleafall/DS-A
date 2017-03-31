//
// Created by aleafall on 16-11-22.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
const int maxn=10005;

vector<int> g[maxn];
vector<int> ans;
int father[maxn];
int n,Max=-1;

int findFather(int x){
    if (father[x] == x) {
        return x;
    } else {
        int F = findFather(father[x]);
        father[x]=F;
        return F;
    }
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faB] = faA;
    }
}

void DFS(int v, int pre, int level){
//    if (level > Max) {
//        Max = level;
//        ans.clear();
//        ans.push_back(v);
//        ret.clear();
//        ret.insert(v);
//    } else if (level == Max) {
//        ans.push_back(v);
//        ret.insert(v);
//    }
    if (g[v].empty()) {
        ans.push_back(v);
        Max=1;
        return;
    }
    if (g[v].size() == 1&&g[v][0]==pre) {
        if (level > Max) {
            Max = level;
            ans.clear();
            ans.push_back(v);
        } else if (level == Max) {
            ans.push_back(v);
        }
        return;
    }
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != pre) {
            DFS(g[v][i], v, level + 1);
        }
    }
}
int main(){
    for (int i = 0; i < maxn; ++i) {
        father[i] = i;
    }
    cin >> n;
    int v1, v2;
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &v1, &v2);
        g[v1].push_back(v2);
        g[v2].push_back(v1);
        Union(v1, v2);
    }
    set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.insert(findFather(i));
    }
    if (st.size() > 1) {
        printf("Error: %d components\n", (int) st.size());
        return 0;
    }
    DFS(1, -1, 0);
    auto temp = ans;
//    int temp = *ret.begin();
//    int temp = ans[0];
    DFS(ans[0], -1, 0);
//    DFS(*ret.begin(), -1, 0);
//    ans.push_back(temp);
//    ret.insert(temp);
    for (auto item:temp) {
        ans.push_back(item);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (i == 0 || ans[i] != ans[i - 1]) {
            printf("%d\n", ans[i]);
        }
    }
//    for (auto item:ret) {
//        cout<<item<<endl;
//    }
    return 0;
}
