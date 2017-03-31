//
// Created by aleafall on 16-11-21.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=2005;

int index=0;
struct Stu{
    int id;
    int Rank[4], Score[4];
}stu[maxn];

bool cmp(Stu a, Stu b){
    return a.Score[index]>b.Score[index];
}
int main(){
    int n,m,q;
    cin >> n>>m;
    map<int,int> mp;
    string sub = "ACME";
    for (int i = 0; i < n; ++i) {
        cin>>stu[i].id>>stu[i].Score[1]>>stu[i].Score[2]>>stu[i].Score[3];
        stu[i].Score[0] = (stu[i].Score[1] + stu[i].Score[2] + stu[i].Score[3]) / 3;
    }
    for (index = 0; index < 4; ++index) {
        sort(stu, stu+n, cmp);
        for (int j = 0; j < n; ++j) {
            if (j && stu[j].Score[index] == stu[j - 1].Score[index]) {
                stu[j].Rank[index] = stu[j - 1].Rank[index];
            } else {
                stu[j].Rank[index] = j + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        mp[stu[i].id] = i;
    }
    for (int i = 0; i < m; ++i) {
        cin>>q;
        if (mp.find(q) != mp.end()) {
            int now = mp[q];
            int Min = INT32_MAX,index=0;
            for (int j = 0; j < 4; ++j) {
                if (stu[now].Rank[j] < Min) {
                    index = j;
                    Min = stu[now].Rank[j];
                }
            }
            cout<<Min<<" "<<sub[index]<<endl;
        } else {
            cout<<"N/A"<<endl;
        }
    }
    return 0;
}