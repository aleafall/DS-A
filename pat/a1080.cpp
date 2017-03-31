//
// Created by aleafall on 16-12-1.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 40005;
const int maxk = 101;

struct Stu {
    int id, ge, gi, gf, Rank;
    int choices[6];
} stu[maxn];

struct Sch {
    int quota;
    vector<int> ac;
} sch[maxk];

bool cmp(Stu a, Stu b) {
    if (a.gf != b.gf) {
        return a.gf > b.gf;
    }
    return a.ge > b.ge;
}

bool cmp1(int a,int b){
    return stu[a].id < stu[b].id;
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &sch[i].quota);
    }
    for (int i = 0; i < n; ++i) {
        stu[i].id = i;
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].gf = stu[i].ge + stu[i].gi;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &stu[i].choices[j]);
        }
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; ++i) {
        if (i && stu[i].gf == stu[i - 1].gf && stu[i].ge == stu[i - 1].ge) {
            stu[i].Rank = stu[i - 1].Rank;
        } else {
            stu[i].Rank = i + 1;
        }
        for (int j = 0; j < k; ++j) {
            int now = stu[i].choices[j];
            if (sch[now].quota > sch[now].ac.size() || stu[sch[now].ac[sch[now].ac.size() - 1]].Rank == stu[i].Rank) {
                sch[now].ac.push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if (sch[i].ac.empty()) {
            printf("\n");
        } else {
            sort(sch[i].ac.begin(), sch[i].ac.end(), cmp1);
            for (int j = 0; j < sch[i].ac.size(); ++j) {
                if (j < sch[i].ac.size() - 1) {
                    printf("%d ", stu[sch[i].ac[j]].id);
                } else {
                    printf("%d\n", stu[sch[i].ac[j]].id);
                }
            }
        }
    }
    return 0;
}
