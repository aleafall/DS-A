//
// Created by aleafall on 16-11-19.
//

#include <iostream>
#include <vector>

using namespace std;

const int maxn=101;

vector<int> vi[maxn];
vector<int> ans;

void DFS(int root, int level){
    if (ans.size() < level) {
        ans.push_back(0);
    }
    if (vi[root].empty()) {
        ans[level-1]++;
    } else {
        for (int i = 0; i < vi[root].size(); ++i) {
            DFS(vi[root][i], level + 1);
        }
    }
}
int main(){
    int n,m,k,id,kid;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            cin>>kid;
            vi[id].push_back(kid);
        }
    }
    DFS(1, 1);
    for (int i = 0; i <ans.size() ; ++i) {
        if (i < ans.size() - 1) {
            cout << ans[i] << " ";
        } else {
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}
